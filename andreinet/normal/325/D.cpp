#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 3005;
const int KMAX = 3005 * 3005 * 2 + 10;

int father[KMAX];
bitset<2 * NMAX> used[NMAX];

int find(int x) {
    int y, p;
    for (y = father[x]; y != father[y]; y = father[y]);
    for (; x != y; x = p) {
        p = father[x];
        father[x] = y;
    }
    return y;
}

void unite(int x, int y) {
    father[find(x)] = find(y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    int k = n * m * 2;
    for (int i = 0; i < k; ++i) {
        father[i] = i;
    }

    const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ans = 0;
    while (q-- > 0) {
        int x, y;
        cin >> x >> y;
        
        if (m == 1) {
            continue;
        }

        x--; y--;
        vector<int> adj[2];
        for (int add = 0; add <= m; add += m) {
            vector<int> ccs;
            for (int d = 0; d < 8; ++d) {
                int nx = x + dx[d], ny = (y + add + dy[d] + 2 * m) % (2 * m);
                if (nx < 0 || nx >= n) {
                    continue;
                }
                if (used[nx][ny]) {
                    int c = find(nx * (2 * m) + ny);
                    if (find(ccs.begin(), ccs.end(), c) == ccs.end()) {
                        ccs.push_back(c);
                    }
                }
            }
            adj[add / m] = ccs;
        }
        bool ok = true;
        for (int c: adj[0]) {
            if (find(adj[1].begin(), adj[1].end(), c) != adj[1].end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
            for (int add = 0; add <= m; add += m) {
                used[x][y + add] = true;
                for (int c: adj[add / m]) {
                    unite(x * (2 * m) + y + add, c);
                }
            }
        }
    }
    cout << ans << '\n';
}