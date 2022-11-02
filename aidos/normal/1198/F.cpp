#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int a[maxn];
set<int> f, s;
int b[maxn];
map<int, int> X;
map<int, int> Y;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(f.count(a[i]) > 0) {
            s.insert(a[i]);
        } else {
            f.insert(a[i]);
        }
    }
    vector<int> g(f.begin(), f.end());
    for(int x: s) g.emplace_back(x);
    int op = 0;
    for(int it = 0; op < 1e7; it++) {
        int A = 0, B = 0;
        for(int i = 0; i < g.size(); i++) {
            if(rand() & 1) {
                b[i] = 1;
                A = __gcd(A, g[i]);
            } else {
                b[i] = 0;
                B = __gcd(B, g[i]);
            }
            op += 2;
        }
        if(A == 1 && B == 1) {
            for(int i = 0; i < g.size(); i++) {
                if(X[g[i]] == 0) {
                    X[g[i]] = b[i] + 1;
                }
                else {
                    Y[g[i]] = b[i] + 1;
                }
            }
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                if(X[a[i]] > 0) {
                    cout << X[a[i]] << " ";
                    X[a[i]] = 0;
                } else {
                    cout << Y[a[i]] << " ";
                }
            }
            return;
        }
    }
    cout << "NO\n";

}

int main() {
    srand(time(0));
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}