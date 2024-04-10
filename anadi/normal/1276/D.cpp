#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;
const int MOD = 998'244'353;

int n;
int dp[N][3];
vector <pair <int, int> > G[N];

void dfs(int u, int pw)
{
    int len = G[u].size() + 1;
    vector <int> pref, suf;

    pref.reserve(len);
    suf.reserve(len);
    
    pref.push_back(1);
    for (auto [v, w]: G[u]) {
        if (w == pw) {
            continue;
        }

        dfs(v, w);
        int last = pref.back();
        
        pref.push_back(1LL * last * (dp[v][0] + dp[v][1]) % MOD);
        suf.push_back(dp[v][0] + dp[v][2]);
    }

    suf.push_back(1);
    for (int i = suf.size() - 2; i >= 0; --i) {
        suf[i] = 1LL * suf[i] * suf[i + 1] % MOD;
    }

    int id = 0;
    for (auto [v, w]: G[u]) {
        if (w == pw) {
            dp[u][1] = 1LL * pref[id] * suf[id] % MOD;
            continue;
        }

        if (w < pw) {
            dp[u][0] = (dp[u][0] + 1LL * pref[id] * dp[v][2] % MOD * suf[id + 1]) % MOD;
        } else {
            dp[u][2] = (dp[u][2] + 1LL * pref[id] * dp[v][2] % MOD * suf[id + 1]) % MOD;
        }

        ++id;
    }

    dp[u][2] = (dp[u][2] + pref.back()) % MOD;
//    printf("dp[%d] = (%d, %d, %d)\n", u, dp[u][0], dp[u][1], dp[u][2]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    dfs(1, 0);
    printf("%d\n", dp[1][2]);
    return 0;
}