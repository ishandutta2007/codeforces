#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
const char el = '\n';
const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.1415926;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define pb push_back
#define debug(x) cout << #x << ": " << x << el
#define left left228
#define right right228
#define prev prev228

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true;} return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true;} return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> mn, mx;
    int sum = 0;
    forn(i, n) {
        int l;
        cin >> l;
        bool ok = 0;
        int mn1 = inf, mx1 = 0;
        while(l--) {
            int x;
            cin >> x;
            if (x > mn1) {
                ok = 1;
            }
            uin(mn1, x);
            uax(mx1, x);
        }
        if (ok) sum++;
        else {
            mn.push_back(mn1);
            mx.push_back(mx1);
        }
    }
    ll ans = n * 1ll * n - (n - sum) * 1ll * (n - sum);
    auto mxx = mx;
    sort(all(mxx));
    forn(i, mn.size()) {
        ans += 1ll * (mxx.end() - upper_bound(all(mxx), mn[i]));
    }
    cout << ans << el;
    return 0;
}