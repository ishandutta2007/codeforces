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
    int q; cin >> q;
    while(q--) {
        ll n, m, k; cin >> n >> m >> k;
        n = abs(n); m = abs(m);
        ll ans = -1;
        if((n + m) & 1) {
            k -= 1;

            for(int a1 = -1; a1 < 2; a1++)
                for(int a2 = -1; a2 < 2; a2++)
                    if((a1 + a2)&1) {
                        n += a1, m += a2;
                        ll kk = k;
                        ll a = (n + m) / 2, b = (m - n) / 2;
                        //cout << a1 << ' ' << a2 << endl;
                        //cout << n << ' ' << m << endl;
                        //cout << a << ' ' << b << endl;
                        //cout << endl;
                        a = abs(a), b = abs(b);
                        int add = 0;
                        if((a + b - k) & 1) {
                            k--;
                            add = -1;
                        }
                        if(k < a + b) {
                        } else {
                            //cout << k + add << endl << endl;
                            ans = max(ans, k + add);
                        }
                        n -= a1, m -= a2;
                        k = kk;
                    }
        }
        ll a = (n + m) / 2, b = (m - n) / 2;
        a = abs(a); b = abs(b);
        int add = 0;
        if((a + b - k) & 1) {
            k--;
            add = -1;
        }
        if(k < a + b) {

        } else {
            ans = max(ans, k + add);
        }
        cout << ans << '\n';
    }

//    struct line {
//        int a, b;
//        ll c;
//    };
//    set<pll> dif;
//    int n; cin >> n;
//    ll ans = 0;
//    vector<pll> v1(n), v2(n);
//    for(int i = 0; i < n; i++) {
//        cin >> v1[i].x >> v1[i].y >> v2[i].x >> v2[i].y;
//        if(v1[i].x == v2[i].x) ans += abs(v1[i].y - v2[i].y;);
//        ans += 1 + __gcd();
//    }
}