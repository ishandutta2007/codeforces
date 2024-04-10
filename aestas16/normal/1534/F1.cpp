/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5;

int n, m, timer, tot, ans, dfn[N + 10], low[N + 10], ideg[N + 10], to[N + 10];
bool instk[N + 10];
stack<int> stk;
vector<vector<char> > mp;
vector<int> e[N + 10];
vector<vector<int> > id, scc;

void tarjan(int u) {
    dfn[u] = low[u] = ++timer, instk[u] = 1, stk.push(u);
    for (auto v : e[u])
        if (dfn[v] == 0) tarjan(v), low[u] = min(low[u], low[v]);
        else if (instk[v]) low[u] = min(low[u], low[v]);
    if (dfn[u] == low[u]) {
        scc.push_back({});
        while (1) {
            int cur = stk.top();
            stk.pop(), instk[cur] = 0, to[cur] = scc.size(), scc.back().push_back(cur);
            if (cur == u) break;
        }
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(m), mp.resize(n + 1, vector<char> (m + 1)), id.resize(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '#') id[i][j] = ++tot;
        }
    for (int i = 1, x; i <= m; i++) fr(x);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == '#') {
                if (i - 1 >= 1 && mp[i - 1][j] == '#') e[id[i][j]].push_back(id[i - 1][j]);
                for (int k = i + 1; k <= n; k++)
                    if (mp[k][j] == '#') {
                        e[id[i][j]].push_back(id[k][j]);
                        break;
                    }
                bool f1 = 0, f2 = 0;
                for (int k = i; k <= n && (f1 == 0 || f2 == 0) && (mp[k][j] != '#' || k == i); k++) {
                    if (j - 1 >= 1 && f1 == 0 && mp[k][j - 1] == '#') e[id[i][j]].push_back(id[k][j - 1]), f1 = 1;
                    if (j + 1 <= m && f2 == 0 && mp[k][j + 1] == '#') e[id[i][j]].push_back(id[k][j + 1]), f2 = 1;
                }
            }
    for (int i = 1; i <= tot; i++)
        if (dfn[i] == 0) tarjan(i);
    for (int i = 0; i < scc.size(); i++)
        for (auto u : scc[i])
            for (auto v : e[u])
                if (to[v] != (i + 1)) ideg[to[v]]++;
    for (int i = 1; i <= scc.size(); i++)
        if (ideg[i] == 0) ans++;
    return printf("%d\n", ans), 0;
}