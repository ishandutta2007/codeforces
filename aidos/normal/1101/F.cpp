#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 10;
int n, m;
int a[maxn];
vector < vector<int> > Q[maxn];
int dp[444][444];
int main () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll V = 0;
    for(int i = 0; i < m; i++) {
        int s, f, c, r;
        cin >> s >> f >> c >> r;
        r = min(f-s, r);
        Q[s].push_back({f, c, r});
    }
    for(int l = 1; l < n; l++) {
        for(int r = l + 1; r <= n; r++) {
            dp[r][0] = a[r] - a[l];
        }
        for(int k = 1; k <= n-l; k++) {
            int optl = l;
            for(int r = l + 1; r <= n; r++) {
                while(optl + 1 < r && max(dp[optl][k-1], a[r] - a[optl]) >= max(dp[optl+1][k-1], a[r] - a[optl+1])) {
                    optl++;
                }
                dp[r][k] = max(dp[optl][k-1], a[r] - a[optl]);
            }
        }
        for(auto v: Q[l]) {
            V = max(V, dp[v[0]][v[2]] * 1ll * v[1]);
        }
    }
    cout << V << "\n";
    return 0;
}