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
 
void dfs(int u) {
    st.push(u);
    low[u] = ++Timer;
    numb[u] = Timer;
    for (auto v : g[u]) {
        if (deleted[v]) continue;
        if (low[v] != 0) low[u] = min(low[u], low[v]);
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

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
            if (pre.first >= 0) for (int d = -1; d <= 1; d += 2) {
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
                // cout << cmpId[v] << endl;
            }
        }
    }

    // cout << cntCmp << endl;

    int res = 0;
    for (int i = 1; i < cntCmp; i++) {
        res += (degIn[i] == 0);
    }
    cout << res << '\n';

    return 0;
}