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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n + 1), pref(n + n + 1);
        forn(i, n) {
            int c;
            cin >> c;
            a[--c]++;
        }
        forn(i, n) {
            b[a[i]]++;
        }
        forn(i, n + 1) {
            pref[i + 1] = pref[i] + b[i];
        }
        int s;
        for (s = n; s > 0; --s) {
            bool ok = 1;
            for (int k = 0; k * s <= n && k < s; ++k) {
                if (pref[k * s + s] - pref[k * s + k + 1] > 0) ok = 0;
            }
            if (ok) break;
        }
        int ans = 0;
        forn(i, n) {
            int t = a[i] / s;
            ans += t;
            t -= a[i] % s;
            ans -= t / (s + 1);
        }
        cout << ans << el;
    }
    return 0;
}