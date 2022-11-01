#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;
const int MOD = 1e9 + 7;

vector<pair<int, int64_t>> G[NMAX];
bool solved[NMAX];
int64_t nodeXor[NMAX];

vector<int64_t> cycles;
vector<int64_t> xors;

void dfs(int node) {
    solved[node] = true;
    xors.push_back(nodeXor[node]);
    for (const auto& p: G[node]) {
        int to = p.first;
        int64_t cost = p.second;
        if (!solved[to]) {
            nodeXor[to] = nodeXor[node] ^ cost;
            dfs(to);
        } else {
            cycles.push_back(nodeXor[node] ^ nodeXor[to] ^ cost);
        }
    }
}

bool flipable[65];

int doGauss(vector<int64_t>& a) {
    int n = SZ(a);
    for (int k = 62; k >= 0; --k) {
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & (1LL << k)) != 0 &&
                    (a[i] < (1LL << (k + 1)))) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            for (int i = 0; i < n; ++i) {
                if (i != pos && (a[i] & (1LL << k)) != 0) {
                    a[i] ^= a[pos];
                }
            }
        }
    }
    int cnt = 0;
    memset(flipable, 0, sizeof flipable);
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            cnt++;
            for (int k = 0; k < 63; ++k) {
                if (a[i] & (1LL << k)) {
                    flipable[k] = true;
                }
            }
        }
    }
    return cnt;
}

int fans = 0;

void solve(int node) {
    cycles.clear();
    xors.clear();
    dfs(node);
    int off = doGauss(cycles);
    for (int k = 62; k >= 0; --k) {
        int cnt = 0;
        for (int64_t v: xors) {
            cnt += (v & (1LL << k)) != 0;
        }
        int xv = (1LL << k) % MOD;
        if (flipable[k]) {
            int add1 = (int64_t) cnt * (SZ(xors) - cnt) % MOD;
            add1 = (int64_t) add1 * ((1LL << (off - 1)) % MOD) % MOD;
            add1 = (int64_t) add1 * xv % MOD;
            int add2 = ((int64_t) cnt * (cnt - 1) / 2 +
                       (int64_t) (SZ(xors) - cnt) * (SZ(xors) - cnt - 1) / 2) % MOD;
            if (add2 < 0) {
                add2 += MOD;
            }
            add2 = (int64_t) add2 * ((1LL << (off - 1)) % MOD) % MOD;
            add2 = (int64_t) add2 * xv % MOD;
            fans = (fans + add1) % MOD;
            fans = (fans + add2) % MOD;
        } else {
            int add = (int64_t) cnt * (SZ(xors) - cnt) % MOD;
            add = (int64_t) add * ((1LL << off) % MOD) % MOD;
            add = (int64_t) add * xv % MOD;
            fans = (fans + add) % MOD;
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        int64_t c;
        cin >> x >> y >> c;
        x--;
        y--;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }

    for (int i = 0; i < n; ++i) {
        if (!solved[i]) {
            solve(i);
        }
    }
    cout << fans << '\n';
}