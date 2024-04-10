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
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128;

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

#define int ll
struct pt {
    int x, y;
    pt() {}
    pt (int _x, int _y) {x = _x, y = _y;}
};
pt operator -(const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
}
int operator %(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}
int sign(int a) {
    return a > 0 ? 1 : (a == 0 ? 0 : -1);
}
bool operator <(const pt &a, const pt &b) {
    if (sign(pt(1, 0) % a) * sign(pt(1, 0) % b) == 0) {
        if (a.y == 0) {
            if (a.x > 0 || pt(1, 0) % b < 0) return 1;
            return 0;
        }
        if (b.x > 0 || pt(1, 0) % a < 0)
            return 0;
        return 1;
    }
    if (sign(pt(1, 0) % a) * sign(pt(1, 0) % b) > 0)
        return a % b > 0;
    return pt(1, 0) % a > 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pt> a(n);
    forn(i, n) cin >> a[i].x >> a[i].y;
    ll ans = 0;
    forn(i, n) {
        vector<pt> b;
        forn(j, n) {
            if (j == i) continue;
            b.push_back(a[j] - a[i]);
        }
        sort(all(b));
        forn(j, n - 1) b.push_back(b[j]);
        ans += (n - 1) * 1ll * (n - 2) * 1ll * (n - 3) / 6ll;
        forn(j, n - 1) {
            int l = j, r = j + n - 1;
            while(r - l > 1) {
                int m = (l + r) >> 1;
                if (b[j] % b[m] > 0) l = m;
                else r = m;
            }
            int k = l - j;
            ans -= k * 1ll * (k - 1) / 2;
        }
    }
    ans *= (n - 4) * 1ll;
    ans /= 2ll;
    cout << ans << el;
    return 0;
}