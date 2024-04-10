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

const int C = 1e8 + 5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;

    auto get = [&](ll x, ll y) -> pl {
        ll g = __gcd(x, y);
        return {x / g, y / g};
    };
   
    map<ll, set<pl>> use;
    map<pl, ll> line;
    map<pl, ll> cnt;
    
    int tot = 0;
    
    while (q--) {
        int t; cin >> t;
        ll x, y; cin >> x >> y;
    
        ll r = x * x + y * y;
        pl p = get(x, y);
    
        if (t == 1) {
            each(pt, use[r]) {
                pl res = get(pt.f + x, pt.s + y);
                cnt[res]++;
            }
    
            use[r].emplace(x, y);
            line[p]++;
            tot++;
        } else if (t == 2) {
            use[r].erase({x, y});
    
            each(pt, use[r]) {
                pl res = get(pt.f + x, pt.s + y);
                cnt[res]--;
            }
    
            line[p]--;
            tot--;
        } else {
            ll ans = tot;
    
            ans -= line[p];
            ans -= cnt[p] * 2;
            
            cout << ans << " " <<'\n';
        }
    }

    return 0;
}
/**
 * Observations
     * Note that we care only about radii
     * Two points are symmetric if they have the same radii
     * and their angles are averaged to same angle
     * So if we have (a, b), (c, d)
     * Then we want to have that y / x = (b + d) / (a + c)
     * We can first find the number of points on each line, that's easy
     * So we just want to find the number of pairs of points which have equal radii and average equal to that
     *  
 */