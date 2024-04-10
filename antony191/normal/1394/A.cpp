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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a, b;
    forn(i, n) {
        int c;
        cin >> c;
        if (c > m) b.push_back(c);
        else a.push_back(c);
    }
    sort(rall(a)); sort(all(b));
    vector<ll> pref((int)a.size() + 1);
    forn(i, a.size()) pref[i + 1] = pref[i] + a[i];
    if (b.empty()) return cout << pref.back() << el, 0;
    int k = (int)b.size();
    ll ans = 0, tmp = 0;
    for (int i = 1; i <= k; i++) {
        tmp += b[k - i];
        if (i * 1ll * (d + 1) < k || i + (i - 1) * 1ll * d > n) continue;
        uax(ans, tmp + pref[min(n - k, n - i - (i - 1) * d)]);
    }
    cout << ans << el;
    return 0;
}