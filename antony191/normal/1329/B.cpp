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
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int dp[31][31];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int d, m;
        cin >> d >> m;
        int k = 0, tmp = d;
        while(tmp > 0) {
            k++;
            tmp >>= 1;
        }
        vector<int> st(30, 1);
        firn(i, 30) st[i] = st[i - 1] * 2ll % m;
        int ans = 0;
        firn(i, 31) {
            if (i <= k) {
                dp[1][i] = (i < k ? st[i - 1] : d - (1 << (k - 1)) + 1);
                ans = (ans + dp[1][i]) % m;
            }
            else dp[1][i] = 0;
        }
        for (int i = 2; i <= 30; i++) {
            firn(j, k + 1) {
                dp[i][j] = 0;
                firn(t, j)
                    dp[i][j] = (dp[i][j] + dp[i - 1][t] * 1ll * (j < k ? st[j - 1] : d - (1 << (k - 1)) + 1)) % m;
                ans = (ans + dp[i][j]) % m;
            }
        }
        ans = (ans % m + m) % m;
        cout << ans << el;
    }
    return 0;
}