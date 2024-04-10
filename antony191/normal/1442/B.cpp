#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 998'244'353;
const ll llinf = 1e18;
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k), pos(n), ok(n), isp(n);
        forn(i, n) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;
        }
        forn(i, k) {
            cin >> b[i];
            b[i]--;
            ok[pos[b[i]]] = i + 1;
        }
        ll ans = 1;
        forn(i, n) {
            if (!ok[i]) continue;
            if (i == 0 && ok[i + 1] > ok[i]) ans = 0;
            else if (i == n - 1 && ok[i - 1] > ok[i]) ans = 0;
            else if (ok[i - 1] > ok[i] && ok[i + 1] > ok[i]) ans = 0;
            if (i > 0 && i < n - 1 && ok[i - 1] < ok[i] && ok[i + 1] < ok[i]) ans = ans * 2ll % mod;
        }
        cout << ans << el;
    }
    return 0;
}