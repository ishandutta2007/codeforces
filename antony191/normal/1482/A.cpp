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

void dress(vector<pair<int, int>> &a) {
    sort(all(a));
    vector<pair<int, int>> b;
    int r = 0;
    for (auto to : a) {
        if (to.y > r) {
            while(!b.empty() && b.back().x == to.x)
                b.pop_back();
            b.push_back(to);
            r = to.y;
        }
    }
    a = b;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    forn(i, n) cin >> A[i];
    forn(i, n) cin >> B[i];
    vector<pair<int, int>> a, b;
    ll sum = 0;
    forn(i, n) {
        int x = A[i], y = B[i];
        sum += abs(x - y);
        if (x < y) a.emplace_back(x, y);
        if (x > y) b.emplace_back(y, x);
    }
    dress(a);
    dress(b);
    int i = 0, j = 0;
    int mx = 0;
    while(i < (int)a.size() && j < (int)b.size()) {
        uax(mx, min(a[i].y, b[j].y) - max(a[i].x, b[j].x));
        if (a[i].y <= b[j].y)
            i++;
        else j++;
    }
    cout << sum - 2ll * mx << el;
    return 0;
}