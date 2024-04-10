#include <bits/stdc++.h>

//#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
//#endif

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

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
const int N = 1003;
int a[N][N];
void bfs(int i, int j) {
    a[i][j] = 2;
    if (i > 0 && a[i - 1][j] == 1) bfs(i - 1, j);
    if (j > 0 && a[i][j - 1] == 1) bfs(i, j - 1);
    if (a[i + 1][j] == 1) bfs(i + 1, j);
    if (a[i][j + 1] == 1) bfs(i, j + 1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    forn(i, n) forn(j, m) {
        char c;
        cin >> c;
        a[i][j] = c == '#';
    }
    bool ok = true;
    int c1 = 0, c2 = 0;
    forn(i, n) {
        bool t = false;
        forn(j, m) {
            if (t && a[i][j] && !a[i][j - 1]) ok = false;
            if (a[i][j]) t = true;
        }
        if (!t) c1++;
    }
    forn(j, m) {
        bool t = false;
        forn(i, n) {
            if (t && a[i][j] && !a[i - 1][j]) ok = false;
            if (a[i][j]) t = true;
        }
        if (!t) c2++;
    }
    if (c1 + c2 > 0 && c1 * c2 == 0) ok = false;
    if (!ok) cout << -1 << el;
    else {
        int ans = 0;
        forn(i, n) forn(j, m) {
            if (a[i][j] == 1) ans++, bfs(i, j);
        }
        cout << ans << el;
    }
    return 0;
}