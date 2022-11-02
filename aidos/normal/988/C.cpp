#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
string s;
void solve() {
    cin >> k;
    map<int, pii> M;
    for(int t = 0; t < k; t++) {
        cin >> n;
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        set<int> S;
        for(int i = 0; i < n; i++) {
            int x = s - a[i];
            if(S.count(x)) continue;
            S.insert(x);
            if(M.count(x)) {
                cout << "YES\n";
                cout << M[x].first << " "<< M[x].second << "\n";
                cout << t + 1 << " " << i + 1 << "\n";
                return;
            }
            M[x] = make_pair(t + 1, i + 1);
        }
    }
    cout << "NO\n";
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