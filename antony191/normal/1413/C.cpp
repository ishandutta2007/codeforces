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
    int m = 6;
    vector<int> a(m);
    forn(i, m) cin >> a[i];
    sort(rall(a));
    int n;
    cin >> n;
    vector<int> b(n);
    forn(i, n) cin >> b[i];
    sort(all(b));
    vector<int> c(n, 0);
    set<pair<int, int>> q;
    forn(i, n) {
        q.emplace(b[i] - a[0], i);
    }
    int ans = inf;
    uin(ans, q.rbegin()->x - q.begin()->x);
    while(true) {
        int i = q.begin()->y;
        if (c[i] == m - 1) break;
        q.erase(q.begin());
        c[i]++;
        q.emplace(b[i] - a[c[i]], i);
        uin(ans, q.rbegin()->x - q.begin()->x);
    }
    cout << ans << el;
    return 0;
}