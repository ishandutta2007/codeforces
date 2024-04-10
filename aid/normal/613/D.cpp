#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, LOGN = 20, INF = 1000 * 1000 * 1000 + 5;
int p[MAXN][LOGN], tin[MAXN], tout[MAXN], id[MAXN], dp[MAXN][2], t;
char c[MAXN];
vector<int> g[MAXN], gc[MAXN];

void dfs(int v) {
    tin[v] = t++;
    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p[v][0]) {
            p[g[v][i]][0] = v;
            dfs(g[v][i]);
        }
    tout[v] = t++;
}

bool cmp(int a, int b) {
    return tin[a] < tin[b];
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLca(int v, int u) {
    if(anc(v, u))
        return v;
    if(anc(u, v))
        return u;
    for(int i = LOGN - 1; i >= 0; i--)
        if(!anc(p[v][i], u))
            v = p[v][i];
    return p[v][0];
}

void solve(int v) {
    dp[v][0] = (c[v]? INF : 0);
    dp[v][1] = 0;
    for(size_t i = 0; i < gc[v].size(); i++) {
        int u = gc[v][i];
        solve(u);
        int dp0 = min(INF, min(dp[v][0] + dp[u][1] + 1, dp[v][0] + dp[u][0]));
        int dp1 = min(min(dp[v][0] + dp[u][1], dp[v][1] + dp[u][0]),
                      dp[v][1] + dp[u][1] + 1);
        dp[v][0] = dp0;
        dp[v][1] = dp1;
    }
    if(!c[v]) {
        int dp0 = 1;
        for(size_t i = 0; i < gc[v].size(); i++) {
            int u = gc[v][i];
            dp0 = min(INF, dp0 + dp[u][1]);
        }
        dp[v][0] = min(dp[v][0], dp0);
    }
    dp[v][1] = min(dp[v][1], dp[v][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    p[0][0] = 0;
    dfs(0);
    int q;
    cin >> q;
    for(int qq = 0; qq < q; qq++) {
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> id[i];
            id[i]--;
            c[id[i]] = true;
        }
        bool bad = false;
        for(int i = 0; i < k; i++)
            if(id[i] && c[p[id[i]][0]]) {
                bad = true;
                break;
            }
        if(bad)
            cout << -1 << '\n';
        else {
            sort(id, id + k, cmp);
            vector<int> v;
            for(int i = 0; i < k; i++)
                v.push_back(id[i]);
            for(int i = 0; i + 1 < k; i++)
                v.push_back(getLca(id[i], id[i + 1]));
            sort(v.begin(), v.end(), cmp);
            v.erase(unique(v.begin(), v.end()), v.end());
            vector<int> st;
            for(size_t i = 0; i < v.size(); i++) {
                while(!st.empty() && !anc(st.back(), v[i]))
                    st.pop_back();
                if(!st.empty())
                    gc[st.back()].push_back(v[i]);
                st.push_back(v[i]);
            }
            solve(st[0]);
            cout << dp[st[0]][1] << '\n';
            for(size_t i = 0; i < v.size(); i++)
                gc[v[i]].clear();
        }
        for(int i = 0; i < k; i++)
            c[id[i]] = false;
    }
    return 0;
}