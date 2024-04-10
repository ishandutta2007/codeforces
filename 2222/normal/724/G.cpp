#include <algorithm>
#include <iostream>
#include <cassert>
#include <bitset>
#include <random>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
int mul(int x, int y) { return (ll)x * y % mod; }

int qpow(int x, int n) {
    int y = 1;
    for (; n; n /= 2) {
        if (n & 1) y = mul(x, y);
        x = mul(x, x);
    }
    return y;
}

int n, m;
vector<pair<int, ll>> adj[100500];
int p[100500];
vector<pair<pii, ll>> edges;
ll g[100500];
bool u[100500];

vector<ll> C[100500];
vector<ll> E[100500];

int f(int i) { return p[i] == i ? i : p[i] = f(p[i]); }

void dfs(int x) {
    u[x] = true;
    for (auto e : adj[x]) {
        if (!u[e.X]) {
            g[e.X] = g[x] ^ e.Y;
            dfs(e.X);
        }
    }
}

int C2(int n) { return (n * ll(n - 1) / 2) % mod; }

void gauss(vector<ll>& A) {
    int n = sz(A);
    int rank = 0;
    REP (c, 61) {
        int r = rank;
        for (; r < n && ((A[r] >> c) & 1) == 0; ++r);
        if (r == n) continue;
        swap(A[rank], A[r]);
        REP (i, n) {
            if (i == rank || ((A[i] >> c) & 1) == 0)
                continue;
            A[i] ^= A[rank];
        }
        ++rank;
    }
    A.resize(rank);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    REP (i, n) p[i] = i;
    REP (i, m) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        if (f(--x) == f(--y)) {
            edges.eb(pii(x, y), w);
        } else {
            adj[x].eb(y, w);
            adj[y].eb(x, w);
            p[f(x)] = f(y);
        }
    }
    REP (i, n) if (!u[i]) {
        dfs(i);
    }
    for (auto e : edges) {
        int x = e.X.X, y = e.X.Y;
        ll w = e.Y;
        ll t = g[x] ^ g[y] ^ w;
        if (t) C[f(x)].pb(t);
    }
    REP (i, n) {
        E[f(i)].pb(g[i]);
        if (i != f(i)) continue;
        gauss(C[i]);
    }
    int res = 0;
    REP (bit, 61) {
        int sum = 0;
        REP (i, n) {
            if (f(i) != i) continue;
            int c[2] = {0, 0};
            int e[2] = {0, 0};
            for (ll x : C[i])
                c[(x >> bit) & 1]++;
            for (ll x : E[i])
                e[(x >> bit) & 1]++;
            int oddC = mul(c[1] > 0 ? qpow(2, c[1] - 1) : 0, qpow(2, c[0]));
            int evenC = sub(qpow(2, c[0] + c[1]), oddC);
            int oddE = mul(e[0], e[1]);
            int evenE = add(C2(e[0]), C2(e[1]));
            sum = add(sum, mul(oddC, evenE));
            sum = add(sum, mul(evenC, oddE));
        }
        res = add(res, mul(sum, qpow(2, bit)));
    }
    cout << res << endl;
    return 0;
}