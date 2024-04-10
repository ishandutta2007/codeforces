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

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 501;
int a[N][N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n < 3) {
        cout << -1 << el;
        return 0;
    }
    int cur = 0;
    forn(i, n) {
        if (i + 3 == n) {
            a[i][i] = cur + 1;
            a[i][i + 1] = cur + 2;
            a[i + 1][i + 1] = cur + 3;
            a[i][i + 2] = cur + 4;
            a[i + 1][i] = cur + 5;
            a[i + 2][i + 1] = cur + 6;
            a[i + 2][i + 2] = cur + 7;
            a[i + 1][i + 2] = cur + 8;
            a[i + 2][i] = cur + 9;
            break;
        }
        for (int j = n - 1; j >= i; --j) a[i][j] = cur + n - j;
        cur += n - i;
        for (int j = n - 1; j > i; --j) a[j][i] = cur + n - j;
        cur += n - i - 1;
    }
    forn(i, n) {
        forn(j, n) cout << a[i][j] << ' ';
        cout << el;
    }
    return 0;
}