#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 1e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;
const int BL = 317;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   //freopen("in.txt", "r", stdin);

    vll pw(19);
    pw[0] = 1;
    for(int i = 1; i < 19; i++) pw[i] = pw[i - 1] * 10;

    vector<ll> al = {(ll)1e18L};
    for(int i = 0; i < 18; i++) {
        for(int j = i + 1; j < 18; j++) {
            for(int k = j + 1; k < 18; k++) {
                for(int a = 1; a < 10; a++)
                    for(int b = 1; b < 10; b++)
                        for(int c = 1; c < 10; c++)
                            al.pb(a * pw[i] + b * pw[j] + c * pw[k]);
            }
            for(int a = 1; a < 10; a++)
                for(int b = 1; b < 10; b++)
                    al.pb(a * pw[i] + b * pw[j]);
        }
        for(int a = 1; a < 10; a++)
            al.pb(a * pw[i]);
    }
    sort(all(al));
    int q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        cout << upper_bound(all(al), r) - lower_bound(all(al), l) << '\n';
    }

//    struct line {
//        int a, b;
//        ll c;
//    };
//    set<pll> dif;
//    int n; cin >> n;
//    ll ans = 0;
//    vector<pll> v1(n), v2(n);
//    vector<line> l(n);
//    for(int i = 0; i < n; i++) {
//        cin >> v1[i].x >> v1[i].y >> v2[i].x >> v2[i].y;
//        if(v1[i].x == v2[i].x) ans += 1 + abs(v1[i].y - v2[i].y);
//        else if(v1[i].y == v2[i].y) ans += 1 + abs(v1[i].x - v2[i].x);
//        ans += 1 + __gcd((ll)abs(v1[i].x - v2[i].x), (ll)abs(v1[i].y - v2[i].y));
//        l[i] = {v1[i].y - v1[i].};
//    }
}