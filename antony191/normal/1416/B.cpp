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

struct op {
    int i, j, x;
    op() {}
    op(int i, int j, int x): i(i), j(j), x(x) {}
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        forn(i, n) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n) {
            cout << -1 << el;
            continue;
        }
        vector<op> ans;
        firn(i, n) {
            if (a[i] % (i + 1)) {
                ans.emplace_back(1, i + 1, i + 1 - a[i] % (i + 1));
                ans.emplace_back(i + 1, 1, 1 + a[i] / (i + 1));
            }
            else {
                ans.emplace_back(i + 1, 1, a[i] / (i + 1));
            }
        }
        firn(i, n) ans.emplace_back(1, i + 1, sum / n);
        cout << (int)ans.size() << el;
        forn(k, ans.size()) {
            cout << ans[k].i << ' ' << ans[k].j << ' ' << ans[k].x << el;
        }
    }
    return 0;
}