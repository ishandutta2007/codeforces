#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 40005;

int to[NMAX];
int values[NMAX];
bool used[NMAX], onCycle[NMAX];
int indvis[NMAX], pvis;
int cycleIndex[NMAX], cycleCount;
int cycleValues[NMAX];

vector<int> rev[NMAX];

int dfs1(int node) {
    used[node] = true;
    indvis[node] = pvis;
    if (to[node] == -1) return -1;

    if (to[node] == node) {
        onCycle[node] = true;
        return -1;
    }
    
    if (used[to[node]]) {
        if (indvis[to[node]] == pvis) {
            onCycle[node] = true;
            return to[node];
        } else {
            return -1;
        }
    }
    
    int ret = dfs1(to[node]);
    if (ret != -1) onCycle[node] = true;
    if (ret == node) ret = -1;
    return ret;
}

void dfs2(int node) {
    used[node] = true;
    cycleIndex[node] = cycleCount;
    cycleValues[cycleCount] |= 1 << values[node];
    if (!used[to[node]])
        dfs2(to[node]);
}

bool dfs3(int node, const string& s, int pos) {
    if (s[pos] - '0' == values[node]) --pos;
    if (pos == -1) return true;
    for (int p: rev[node])
        if (dfs3(p, s, pos))
            return true;
    return false;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> matrix(n);
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];

    vector<int> di(10), dj(10);
    for (int i = 0; i < 10; ++i)
        cin >> di[i] >> dj[i];

    memset(to, -1, sizeof to);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            values[i * m + j] = matrix[i][j] - '0';

            int k = matrix[i][j] - '0';
            int ni = i + di[k], nj = j + dj[k];
            int next;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) next = i * m + j;
            else next = ni * m + nj;
            to[i * m + j] = next;
            rev[next].push_back(i * m + j);
        }
    }

    n = n * m;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
            pvis++;
        }
    }
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i) {
        if (onCycle[i] && !used[i]) {
            dfs2(i);
            cycleCount++;
        }
    }

    while (q-- > 0) {
        string curr;
        cin >> curr;

        memset(used, 0, sizeof used);
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (onCycle[i]) {
                int cycle = cycleIndex[i], mask = cycleValues[cycle];
                int pos = SZ(curr) - 1;
                while (pos >= 0 && (mask & (1 << curr[pos] - '0')))
                    pos--;
                if (pos == -1) {
                    ok = true;
                    goto FINISH;
                }
                for (int j = i; !used[j]; j = to[j]) {
                    used[j] = true;
                    for (int p: rev[j]) {
                        if (!onCycle[p] && dfs3(p, curr, pos)) {
                            ok = true;
                            goto FINISH;
                        }
                    }
                }
            }
        }

        FINISH:;

        cout << (ok ? "YES": "NO") << '\n';
    }
}