#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef __int128_t i128;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;

    ll l = 1;
    ll r = n; 

    pl lz;

    auto eval = [&](pl val) -> ll {
        return (val.f - l) * lz.s + lz.f + val.s;
    };

    auto get = [&](pl val) -> pl { 
        return {val.f, eval(val)};
    };

    auto make = [&](pl val) -> pl {
        ll x = val.f;
        ll y = val.s;
        y -= lz.f;
        y -= (x - l) * lz.s;
        return {x, y};
    };

    auto convex = [&](pl a, pl b, pl c) -> bool {
        a.f -= b.f;
        a.s -= b.s;
        c.f -= b.f;
        c.s -= b.s;
        i128 lef = (i128)a.f * c.s;
        i128 rig = (i128)a.s * c.f;
        return rig > lef;
    };

    vpl v; // x coordinate, slope
    v.eb(l, 0); 

    f0r(i, m) {
        int t; cin >> t;
        if (t == 1) { // basically just a reset
            ll k; cin >> k;
            l -= k;
            v.clear();
            lz.f = lz.s = 0;
            v.eb(l, 0);
        } else if (t == 2) {
            ll k; cin >> k;
            pl nxt = make({r + 1, 0});
            r += k;
            while (sz(v) >= 2 && !convex(get(v[sz(v) - 2]), get(v[sz(v) - 1]), get(nxt))) v.pop_back();
            if (eval(v.back()) != 0) v.pb(nxt);

        } else {
            ll b, s; cin >> b >> s;
            lz.f += b;
            lz.s += s;
            while (sz(v) >= 2 && eval(v.back()) >= eval(v[sz(v) - 2])) v.pop_back();
        }
        cout << v.back().f - l + 1 << " " << eval(v.back()) << '\n';
    }
    return 0;
}