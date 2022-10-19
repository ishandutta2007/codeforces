#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;

int encode(int x, int y) { return x * m + y; }

vector<int> g[N];

int deleted[N];
int numb[N], low[N];
int Timer = 0;
int cntCmp = 0;
vector<int> comp[N];
int cmpId[N];
stack<int> st;
bool ch[N];

void dfs(int u) {
    st.push(u);
    low[u] = ++Timer;
    numb[u] = Timer;
    for (auto v : g[u]) {
        if (deleted[v]) continue;
        if (low[v] != 0)
            low[u] = min(low[u], low[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (numb[u] == low[u]) {
        cntCmp++;
        int cur;
        do {
            cur = st.top();
            st.pop();
            comp[cntCmp].push_back(cur);
            cmpId[cur] = cntCmp;
            deleted[cur] = 1;
        } while (cur != u);
    }
}

vector<int> gc[N], rgc[N];
bool vis[N];
bool rem[N];

void dfsc(int u) {
    vis[u] = true;
    bool ok = false;
    for (int e : rgc[u]) {
        if (!vis[e]) dfsc(e);
        ok |= rem[e];
    }
    if (ch[u] && ok) ch[u] = false;
    rem[u] = (ok | ch[u]);
}

pair<int, int> dp[N];
bool dped[N];

void dfsdp(int u) {
    dped[u] = true;
    for (int e : gc[u]) {
        if (!dped[e]) dfsdp(e);
        dp[u].first = min(dp[u].first, dp[e].first);
        dp[u].second = max(dp[u].second, dp[e].second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> a(m);
    for (int &e : a) cin >> e;

    for (int j = 0; j < m; j++) {
        pair<int, int> pre = {-1, j};
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '#') g[n * m].push_back(encode(i, j));
            if (pre.first >= 0 && s[i][j] != '.') {
                g[encode(pre.first, pre.second)].push_back(encode(i, j));
                if (pre.first + 1 == i) {
                    g[encode(i, j)].push_back(encode(pre.first, pre.second));
                }
            }
            if (s[i][j] != '.') pre = {i, j};
            if (pre.first >= 0)
                for (int d = -1; d <= 1; d += 2) {
                    int jj = j + d;
                    if (jj < 0 || jj >= m || s[i][jj] == '.') continue;
                    g[encode(pre.first, pre.second)].push_back(encode(i, jj));
                }
        }
    }
    dfs(n * m);
    vector<int> degIn(cntCmp, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = encode(i, j);
            for (int v : g[u]) {
                if (cmpId[u] == cmpId[v]) continue;
                degIn[cmpId[v]]++;
                gc[cmpId[u]].push_back(cmpId[v]);
                rgc[cmpId[v]].push_back(cmpId[u]);
                // cout << cmpId[v] << endl;
            }
        }
    }


    for (int i = 1; i < cntCmp; i++) {
        sort(gc[i].begin(), gc[i].end());
        gc[i].erase(unique(gc[i].begin(), gc[i].end()), gc[i].end());
        sort(rgc[i].begin(), rgc[i].end());
        rgc[i].erase(unique(rgc[i].begin(), rgc[i].end()), rgc[i].end());
    }

    // cout << cntCmp << endl;

    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt += (s[i][j] == '#');
            if (cnt == a[j] && s[i][j] == '#') {
                ch[cmpId[encode(i, j)]] = 1;
                break;
            }
        }
    }

    for (int i = 1; i < cntCmp; i++) {
        if (!vis[i]) dfsc(i);
    }

    vector<int> l(cntCmp, 1e9), r(cntCmp, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;
            int foo = encode(i, j);
            l[cmpId[foo]] = min(l[cmpId[foo]], j);
            r[cmpId[foo]] = max(r[cmpId[foo]], j);
        }
    }

    vector<int> to_done;
    for (int i = 1; i < cntCmp; i++) dp[i] = {1e9, -1};

    for (int i = 1; i < cntCmp; i++) {
        if (ch[i]) dp[i] = {l[i], r[i]}, to_done.push_back(i);
    }


    vector<int> to_get;

    for (int i = 1; i < cntCmp; i++) {
        if (degIn[i] == 0) dfsdp(i), to_get.push_back(i);
    }

    sort(to_done.begin(), to_done.end(),
         [&](int u, int v) { return l[u] < l[v]; });

    sort(to_get.begin(), to_get.end(),
         [&](int u, int v) { return dp[u].second < dp[v].second; });

    vector<int> dpp(to_done.size(), 0);
    vector<int> suff(to_done.size());
    int curr = 1e9;
    int id = (int) to_get.size() - 1;
    for (int i = (int) to_done.size() - 1; i >= 0; i--) {
        while (id >= 0 && dp[to_get[id]].second >= r[to_done[i]]) {
            curr = min(curr, dp[to_get[id]].first);
            id--;
        }
        suff[i] = curr;
    }
    // cout << "to_done: " << endl;
    // for (int e : to_done) {
    //     cout << e << ' ' << l[e] << ' ' << r[e] << endl;
    //     for (int ee : comp[e]) cout << "(" << (ee / m) << ' ' << (ee % m) <<
    //     ")" << ' '; cout << endl;
    // }
    // cout << "to_get: " << endl;
    // for (int e : to_get) {
    //     cout << e << ' ' << dp[e].first << ' ' << dp[e].second << endl;
    //     for (int ee : comp[e]) cout << "(" << (ee / m) << ' ' << (ee % m) <<
    //     ")" << ' '; cout << endl;
    // }
    // for (int i = 0; i < to_done.size(); i++) {
    // 	cout << suff[i] << endl;
    // }

    int id2 = -1;
    for (int i = 0; i < to_done.size(); i++) {
        int ll = suff[i];
        while (id2 + 1 < to_done.size() && r[to_done[id2 + 1]] < ll) {
            id2++;
        }
        if (id2 != -1)
            dpp[i] = dpp[id2] + 1;
        else
            dpp[i] = 1;
        // cout << i << ' ' << id2 << endl;
    }

    if (dpp.empty()) return cout << 0 << endl, 0;

    cout << dpp.back() << endl;

    return 0;
}