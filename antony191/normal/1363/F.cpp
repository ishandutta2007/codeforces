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
const int inf = 1000'000'000, mod = 1000'000'007;
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

const int N = 2002;
int d[N][N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s, t;
        vector<int> a(n), b(n);
        cin >> s >> t;
        forn(i, n) {
            a[i] = s[i] - 'a';
            b[i] = t[i] - 'a';
        }
        sort(all(a)); sort(all(b));
        if (a != b) {
            cout << -1 << el;
            continue;
        }
        vector<int> c1(26), c2(26);
        int cnt = 0;
        forn(i, n) {
            if (!c1[s[i] - 'a']++) cnt++;
            c2.assign(26, 0);
            int tmp = cnt;
            forn(j, n) {
                if (c1[t[j] - 'a'] == ++c2[t[j] - 'a']) tmp--;
                d[i + 1][j + 1] = 0;
                if (!tmp && s[i] == t[j])
                    d[i + 1][j + 1] = d[i][j] + 1;
                uax(d[i + 1][j + 1], max(d[i + 1][j], d[i][j + 1]));
            }
        }
        cout << n - d[n][n] << el;
    }
    return 0;
}