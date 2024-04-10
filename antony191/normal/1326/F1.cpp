#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.end(), v.begin()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int N = 14, C = 20'000;
int g[N][N];
vector<ll> ans[C][N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, n) forn(j, n) {
        char s;
        cin >> s;
        g[i][j] = s - '0';
    }
    vector<pair<int, int>> q;
    firn(mask,1 << n) {
        int c = __builtin_popcount(mask);
        if (c > 1) q.emplace_back(c, mask);
        forn(i, n) {
            if ((1 << i) & mask)
                ans[mask][i].resize(1 << (c - 1));
        }
    }
    forn(i, n) ans[1 << i][i][0] = 1ll;
    sort(all(q));
    for (auto to : q) {
        auto mask = to.y, c = to.x;
        forn(i, n) {
            if (!(mask & (1 << i))) continue;
            forn(j, n) {
                if (j == i || !(mask & (1 << j))) continue;
                forn(k, 1 << (c - 2)) ans[mask][i][k + (g[i][j] << (c - 2))] += ans[mask - (1 << i)][j][k];
            }
        }
    }
    vector<ll> sum(1 << (n - 1));
    forn(i, n) {
        forn(k, 1 << (n - 1)) sum[k] += ans[(1 << n) - 1][i][k];
    }
    output(sum);
    return 0;
}