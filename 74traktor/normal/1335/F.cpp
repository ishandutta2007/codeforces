#include<bits/stdc++.h>

using namespace std;

int n, m;
int const maxn = 1e6 + 5;
vector < int > g[maxn], G[maxn];
char oks[maxn];
int used[maxn], lst[maxn], good[maxn];
vector < int > goal;

inline int get(int i, int j) {
    return (i - 1) * m + j - 1;
}

inline void add(int i1, int j1, int i2, int j2) {
    g[get(i1, j1)].push_back(get(i2, j2));
    G[get(i2, j2)].push_back(get(i1, j1));
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 0) lst[u] = v, dfs(u);
        else if (used[u] == 1) {
            int pos = v;
            while (1) {
                goal.push_back(pos);
                if (pos == u) break;
                pos = lst[pos];
            }
        }
    }
    used[v] = 2;
}

void dfs1(int v, int pos) {
    if (pos == (int)goal.size()) pos = 0;
    used[v] = 3;
    if (oks[v] == '0') good[pos] = 1;
    for (auto u : G[v]) {
        if (used[u] != 3) {
            dfs1(u, pos + 1);
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int answer1 = 0, answer2 = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> oks[m * (i - 1) + j - 1];
                used[m * (i - 1) + j - 1] = 0, g[m * (i - 1) + j - 1] = {}, G[m * (i - 1) + j - 1] = {};
            }
        }
        char go;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> go;
                if (go == 'L') add(i, j, i, j - 1);
                else if (go == 'R') add(i, j, i, j + 1);
                else if (go == 'U') add(i, j, i - 1, j);
                else add(i, j, i + 1, j);
            }
        }
        for (int i = 0; i < n * m; ++i) {
            if (used[i] == 0) {
                goal = {}, dfs(i);
                for (int pos = 0; pos < (int)goal.size(); ++pos) good[pos] = 0;
                for (auto key : goal) used[key] = 3;
                int cur = -1;
                for (auto key : goal) {
                    cur++, dfs1(key, cur);
                    //cout << key << ' ' << cur << endl;
                }
                answer1 += (int)goal.size();
                for (int pos = 0; pos < (int)goal.size(); ++pos) answer2 += good[pos];
            }
        }
        cout << answer1 << " " << answer2 << '\n';
    }
    return 0;
}