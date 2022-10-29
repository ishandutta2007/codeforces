#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

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
const int inf = 1000'000'000, mod = 1000'000'007, mod2 = 998'244'353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

//#define forn(i, n) for (int i = 0; i < (int)n; ++i)
//#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
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

bool query(int h, int w, int i1, int j1, int i2, int j2, bool type) {
    if (type) {
        swap(h, w);
        swap(i1, j1);
        swap(i2, j2);
    }
    cout << "? " << h << ' ' << w << ' ' << i1 + 1 << ' ' << j1 + 1 << ' ' << i2 + 1 << ' ' << j2 + 1 << endl;
    int k;
    cin >> k;
    return k;
}
bool check(int n, int m, int t, bool type) {
    if (n == 1) return true;
    int k = n / 2;
    if (!query(k * t, m, 0, 0, k * t, 0, type))
        return false;
    return check(k, m, t, type);
}
bool bad_check(int n, int m, int t, bool type) {
    int k = 1;
    while(k <= n) k <<= 1;
    k >>= 1;
    if (!check(k, m, t, type))
        return false;
    if (k == n)
        return true;
    return query((n - k) * t, m, 0, 0, k * t, 0, type);
}
int solve(int n, int m, int type = 0) {
    int n1 = n, n2 = n;
    for (int i = 2; i <= n1; i++) {
        while(n % i == 0 && n1 % i == 0) {
            if (!bad_check(i, m, n / i, type))
                break;
            n /= i;
        }
        while(n1 % i == 0) n1 /= i;
    }
    n2 /= n;
    int ans = 0;
    for (int i = 1; i <= n2; i++)
        ans += n2 % i == 0;
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = solve(n, m, 0) * solve(m, n, 1);
    cout << "! " << ans << el;
    return 0;
}