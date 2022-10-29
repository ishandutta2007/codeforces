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

int num[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a, b(21), fac(21);
        for (int i = 2; n > 0; i++) {
            a.push_back(n % i);
            b[a.back()]++;
            n /= i;
        }
        fac[0] = 1;
        firn(i, 21) fac[i] = fac[i - 1] * 1ll * i;
        sort(all(a));
        n = (int)a.size();
        ll ans = 1ll;
        forn(i, a.size()) ans *= 1ll * (i + 1 - max(0ll, a[i] - 1));
        forn(i, 21) ans /= fac[b[i]];
        ll tmp = 1ll;
        if (a[0] == 0) {
            firn(i, a.size()) tmp *= 1ll * (i - max(0ll, a[i] - 1));
            firn(i, 21) tmp /= fac[b[i]];
            tmp /= fac[b[0] - 1];
            ans -= tmp;
        }
        cout << ans - 1 << el;
    }
    return 0;
}