#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
const ll mod = 1e9 + 7, mod1 = 998244353, mod2 = 900900929;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll bp(ll a, ll n, ll m){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return res;
}


void solve(){
    int n;
    cin >> n;
    ll p;
    cin >> p;

    ll ans = 0, ans1 = 0, ans2 = 0;

    map <int, int> mp;

    while(n--){
        int x;
        cin >> x;
        mp[-x]++;
    }

    for(auto i : mp){
        ll t = bp(p, -i.fi, mod), t1 = bp(p, -i.fi, mod1), t2 = bp(p, -i.fi, mod2), sc = i.se;
        if(!ans && !ans1){
            if(sc % 2)ans = t, ans1 = t1, ans2 = t2;
        }else{
            while(sc && (ans || ans1 || ans2)){
                ans -= t;
                if(ans < 0)ans += mod;
                ans1 -= t1;
                if(ans1 < 0)ans1 += mod1;
                ans2 -= t2;
                if(ans2 < 0)ans2 += mod2;
                sc--;
            }
            if(sc % 2)ans = t, ans1 = t1, ans2 = t2;
        }
    }

    cout << ans << "\n";

}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t;
    cin >> t;

    while(t--)solve();

    return 0;
}