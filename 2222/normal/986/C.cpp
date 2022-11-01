#include <bits/stdc++.h>

#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (decltype(a) i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first

using namespace std;

using pii = pair<int, int>;

const int N = (1 << 22);

bool u[2][N];

void dfs(int k, int x) {
    if (!u[k][x]) return;
    u[k][x] = false;
    if (k == 0) {
        dfs(1, (N - 1) ^ x);
        return;
    }
    dfs(0, x);
    REP (i, 22) {
        if (x & 1 << i) {
            dfs(1, x ^ 1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    fill(u[1], u[1] + N, true);
    REP (i, m) {
        int x;
        cin >> x;
        u[0][x] = true;
    }
    int res = 0;
    REP (i, (1 << n)) {
        if (u[0][i]) {
            ++res;
            dfs(0, i);
        }
    }
    cout << res << endl;
    return 0;
}