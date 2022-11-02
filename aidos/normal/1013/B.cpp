#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
vector<int> a[maxn];
vector<int> b[maxn];
int c[maxn];
void solve() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        a[c[i]].push_back(i);
        b[c[i]&x].push_back(i);
    }
    for(int i = 0; i < maxn; i++) {
        if(a[i].size() > 1) {
            cout << 0 << "\n";
            return;
        }
    }
    for(int i = 0; i < maxn; i++) {
        if(b[i].size() == 0) continue;
        if(a[i].size() == 1) {
            if(b[i].size() == 1 && b[i][0] == a[i][0]) {
                continue;
            }
            cout << 1 << "\n";
            return;
        }
    }
    for(int i = 0; i < maxn; i++) {
        if(b[i].size() > 1) {
            cout << 2 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}