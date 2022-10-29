#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
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
const ll llinf = 1e18, mod = 998244353;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 3003;
int d[N][N], e[N][N], f[N][N], st2[N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    st2[0] = 1;
    firn(i, n) {
        st2[i] = st2[i - 1] * 2ll % mod;
    }
    int ans = 0;
    forn(i, n + 1) d[i][0] = n - i + 1;
    for (int i = n - 1; i >= 0; i--) {
        firn(j, m + 1) {
            d[i][j] = d[i + 1][j];
            if (s[i] != t[j - 1]) continue;
            d[i][j] = (d[i][j] + d[i + 1][j - 1]) % mod;
        }
    }
    forn(i, n) {
        if (i + m > n) break;
        ans = (ans + (d[i][m] - d[i + 1][m]) * 1ll * st2[i] % mod) % mod;
    }
    forn(i, m) {
        forn(j, m - i) {
            if (s[i] == t[m - j - 1]) {
                e[i][j] = (i > 0 ? e[i - 1][j + 1] : 1);
                if (j == 0) ans = (ans + e[i][j] * 1ll * d[i + 1][m - i - j - 1]) % mod;
            }
            if (s[i] == t[m - i - j - 1]) e[i][j] = (e[i][j] + (i > 0 ? e[i - 1][j] : 1)) % mod;
        }
    }
    cout << ans << el;
    return 0;
}