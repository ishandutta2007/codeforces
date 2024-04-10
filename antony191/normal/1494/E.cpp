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

const int N = 200'001;
map<int, char> q[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int cnt = 0, cnt_good = 0;
    while(m--) {
        char com;
        cin >> com;
        if (com == '?') {
            int k;
            cin >> k;
            cout << (((k & 1) ? cnt : cnt_good) ? "YES" : "NO") << el;
            continue;
        }
        if (com == '+') {
            int v, u;
            char c;
            cin >> v >> u >> c;
            v--; u--;
            q[v][u] = c;
            if (q[u].find(v) != q[u].end()) {
                cnt++;
                if (q[u][v] == c)
                    cnt_good++;
            }
            continue;
        }
        int v, u;
        cin >> v >> u;
        v--; u--;
        if (q[u].find(v) != q[u].end()) {
            cnt--;
            if (q[u][v] == q[v][u])
                cnt_good--;
        }
        q[v].erase(u);
    }
    return 0;
}