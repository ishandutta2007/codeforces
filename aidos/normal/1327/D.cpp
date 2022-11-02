#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 100;
vector<int> d[maxn];
int p[maxn];
int n;
int c[maxn];
int u[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        u[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        int j = i;
        vector<int> cur;
        while(u[j] == 0) {
            cur.emplace_back(j);
            u[j] = 1;
            j = p[j];
        }
        int m = cur.size();
        for(int x: d[m]) {
            for(int t = 0; t < x; t++) {
                int ok = 1;
                for(int j = t; j < m; j += x) {
                    ok &= c[cur[t]] == c[cur[j]];
                }
                if(ok) {
                    ans = min(ans, x);
                }
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j * i < maxn; j++) {
            d[i*j].emplace_back(i);
        }
    }
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}