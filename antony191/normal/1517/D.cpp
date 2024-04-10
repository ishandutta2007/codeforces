#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000000001, mod = 1000000007, mod2 = 998244353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

const int N = 501;
int a[N][N], b[N][N];

#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;

int q[N * N], q1[N * N];

void add(int i, int j, int w) {
    uin(q[i], q1[j] + w);
}
int ans[N][N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, n * m) q[i] = inf;
    forn(i, n) forn(j, m - 1) {
        cin >> a[i][j];
        uin(q[i * m + j], a[i][j]);
        uin(q[i * m + j + 1], a[i][j]);
    }
    forn(i, n - 1) forn(j, m) {
        cin >> b[i][j];
        uin(q[i * m + j], b[i][j]);
        uin(q[(i + 1) * m + j], b[i][j]);
    }
    for (int t = 2; t <= k / 2; t++) {
        forn(i, n * m) {
            q1[i] = q[i];
            q[i] = inf;
        }
        forn(i, n) forn(j, m) {
            if (j < m - 1) add(i * m + j, i * m + j + 1, a[i][j]);
            if (j > 0) add(i * m + j, i * m + j - 1, a[i][j - 1]);
            if (i < n - 1) add(i * m + j, (i + 1) * m + j, b[i][j]);
            if (i > 0) add(i * m + j, (i - 1) * m + j, b[i - 1][j]);
        }
    }
    forn(i, n) forn(j, m) {
        ans[i][j] = 2 * q[i * m + j];
    }
    forn(i, n) {
        forn(j, m) {
            cout << ((k & 1) ? -1 : ans[i][j]) << ' ';
        }
        cout << el;
    }
    return 0;
}