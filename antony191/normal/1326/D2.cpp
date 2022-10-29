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

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        bool ok = true;
        forn(i, n) if (s[i] != s[n - 1 - i]) ok = false;
        if (ok) {
            cout << s << el;
            continue;
        }
        vector<int> a(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i < r) a[i] = min(r - i, a[l + r - i]);
            while(i - a[i] > 0 && i + a[i] < n - 1 && s[i - a[i] - 1] == s[i + a[i] + 1]) a[i]++;
            if (i + a[i] > r) r = i + a[i], l = i - a[i];
        }
        vector<int> b(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i < r) b[i] = min(r - i, b[l + r - i]);
            while(i - b[i] > 0 && i + b[i] < n && s[i - b[i] - 1] == s[i + b[i]]) b[i]++;
            if (i + b[i] > r) r = i + b[i], l = i - b[i];
        }
        vector<pair<int, int>> p, q;
        forn(i, n) {
            p.emplace_back(i - a[i], 2 * i);
            q.emplace_back(i + a[i], 2 * i);
        }
        forn(i, n) {
            if (!b[i]) continue;
            p.emplace_back(i - b[i], 2 * i - 1);
            q.emplace_back(i + b[i] - 1, 2 * i - 1);
        }
        sort(all(p)); sort(rall(q));
        set<int> p1, q1;
        int mx1 = -2, mx2 = n + n, l = 0, r = 0, l1 = -1, r1 = n, ans = 0;
        forn(i, n) {
            while(l < (int)p.size() && p[l].x <= i) {
                p1.insert(p[l].y);
                l++;
            }
            while(!p1.empty() && *p1.rbegin() > n - 1) p1.erase(*p1.rbegin());
            mx1 = (p1.empty() ? -2 : *p1.rbegin());
            while(r < (int)q.size() && q[r].x >= n - 1 - i) {
                q1.insert(q[r].y);
                r++;
            }
            while(!q1.empty() && *q1.begin() < n - 1) q1.erase(q1.begin());
            mx2 = (q1.empty() ? n + n : *q1.begin());
            if (mx1 >= 0 && uax(ans, mx1 + 1)) {
                l1 = mx1 - i;
                r1 = n - i;
            }
            if (mx2 <= 2 * (n - 1) && uax(ans, 2 * (n - 1) - mx2 + 1)) {
                l1 = i - 1;
                r1 = mx2 - (n - 1 - i);
            }
            if (s[i] != s[n - 1 - i]) break;
        }
        assert(l1 < r1);
        forn(i, l1 + 1) cout << s[i];
        for (int i = r1; i < n; i++) cout << s[i];
        cout << el;
    }
    return 0;
}