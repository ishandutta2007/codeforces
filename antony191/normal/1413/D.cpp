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
const int inf = 2000'000'000, mod = 1000'000'007;
const ll llinf = 1e18;
const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

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
    int n;
    cin >> n;
    vector<int> a(n + n, -1);
    char c;
    int cnt = 0;
    bool bad = false;
    forn(i, n + n) {
        cin >> c;
        if (c == '-') {
            cin >> a[i];
            a[i]--;
            cnt--;
        }
        else cnt++;
        if (cnt < 0) {
            bad = true;
            break;
        }
        if (i > 0 && a[i - 1] >= 0 && a[i] >= 0 && a[i - 1] > a[i]) {
            bad = true;
            break;
        }
    }
    if (bad) return cout << "NO" << el, 0;
    vector<int> stack, ans(n + n, -1);
    forn(i, n + n) {
        if (a[i] == -1) stack.push_back(i);
        else {
            ans[stack.back()] = a[i];
            stack.pop_back();
        }
    }
    set<int> q;
    forn(i, n + n) {
        if (a[i] == -1) q.insert(ans[i]);
        else {
            if (*q.begin() != a[i]) return cout << "NO" << el, 0;
            q.erase(q.begin());
        }
    }
    cout << "YES" << el;
    forn(i, n + n) if (ans[i] >= 0) cout << ans[i] + 1 << ' ';
    cout << el;
    return 0;
}