#include <bits/stdc++.h>

using namespace std;

#define int long long

int maxk[4];
int dp[200005][11];
multiset < int > tmp[4];
int sum_c;
vector < int > sum_d;
vector < pair < int, int > > can;

void dfs(int v, int stop, int i, int pos){
    if (v == stop){
        int add = 0, imax = 0;
        for (auto key : sum_d) add += key, imax = max(imax, key);
        int cnt = sum_d.size();
        if (pos + cnt >= 10){
            dp[i + 1][pos + cnt - 10] = max(dp[i + 1][pos + cnt - 10], dp[i][pos] + add + imax);
        }
        else dp[i + 1][pos + cnt] = max(dp[i + 1][pos + cnt], dp[i][pos] + add);
        return;
    }
    if (sum_c + can[v].first <= 3){
        sum_c += can[v].first;
        sum_d.push_back(can[v].second);
        dfs(v + 1, stop, i, pos);
        sum_c -= can[v].first;
        sum_d.pop_back();
    }
    dfs(v + 1, stop, i, pos);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, c, d;
    cin >> n;
    maxk[1] = 3, maxk[2] = 1, maxk[3] = 1;
    for (int i = 1; i <= n + 1; ++i) for (int j = 0; j <= 9; ++j) dp[i][j] = -1e18;
    dp[1][0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> k;
        for (int j = 1; j <= 3; ++j) tmp[j] = {};
        for (int j = 1; j <= k; ++j){
            cin >> c >> d;
            tmp[c].insert(d);
        }
        for (int j = 1; j <= 3; ++j){
            while ((int)tmp[j].size() > maxk[j]){
                tmp[j].erase(tmp[j].find((*tmp[j].begin())));
            }
        }
        can = {};
        for (int j = 1; j <= 3; ++j){
            for (auto key : tmp[j]) can.push_back({j, key});
        }
        for (int pos = 0; pos <= 9; ++pos){
            if (dp[i][pos] < 0) continue;
            sum_c = 0;
            sum_d = {};
            dfs(0, (int)can.size(), i, pos);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; ++i) ans = max(ans, dp[n + 1][i]);
    cout << ans << '\n';
    return 0;
}