#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < pair < int, int > > g[513];
bitset < 100005 > dp[513];
int cnt[513];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, c;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> k;
        int mask = 0;
        for (int j = 1; j <= k; ++j){
            cin >> x;
            mask += (1<<(x - 1));
        }
        dp[mask][i] = 1;
    }
    for (int mask = 0; mask <= 511; ++mask){
        for (int j = 0; j < 9; ++j){
            if ((mask&(1<<j)) > 0){
                dp[mask] |= dp[(mask^(1<<j))];
            }
        }
    }
    for (int i = 1; i <= m; ++i){
        cin >> c >> k;
        int mask = 0;
        for (int j = 1; j <= k; ++j){
            cin >> x;
            mask += (1<<(x - 1));
        }
        //cout << mask << endl;
        g[mask].push_back({c, i});
    }
    for (int i = 0; i <= 511; ++i) cnt[i] = dp[i].count();
    for (int i = 0; i <= 511; ++i) sort(g[i].begin(), g[i].end());
    int mx = -1, min_sum = 1e10, ans_i, ans_j;
    for (int i = 0; i <= 511; ++i){
        for (int j = 0; j <= 511; ++j){
            int cur = cnt[(i|j)];
            if (cur > mx){
                if ((int)g[i].size() == 0 || g[j].size() == 0) continue;
                if (i == j && (int)g[i].size() == 1) continue;
                mx = cur;
                if (i == j) min_sum = g[i][0].first + g[i][1].first, ans_i = g[i][0].second, ans_j = g[i][1].second;
                else{
                    min_sum = g[i][0].first + g[j][0].first, ans_i = g[i][0].second, ans_j = g[j][0].second;
                }
            }
            else if (cur == mx){
                if ((int)g[i].size() == 0 || g[j].size() == 0) continue;
                if (i == j && (int)g[i].size() == 1) continue;
                if (i == j){
                    if (g[i][0].first + g[i][1].first < min_sum) min_sum = g[i][0].first + g[i][1].first, ans_i = g[i][0].second, ans_j = g[i][1].second;
                }
                else{
                    if (g[i][0].first + g[j][0].first < min_sum) min_sum = g[i][0].first + g[j][0].first, ans_i = g[i][0].second, ans_j = g[j][0].second;
                }
            }
        }
    }
    cout << ans_i << " " << ans_j << '\n';
    return 0;
}