#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set <pll> st;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll temp = 0;

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        temp += sz(st) - st.order_of_key({a[i], inf});
        st.insert({a[i], i});
    }

    if(temp <= k){
        vout(n * (n - 1) / 2);
    }

    ordered_set <pll> l, r;

    l.insert({a[1], 1});

    temp = 0;

    for(int i = 3; i <= n; i++){
        if(a[1] > a[i])temp++;
        temp += sz(r) - r.order_of_key({a[i], inf});
        r.insert({a[i], i});
    }

    ll uk = 3;

    for(int i = 1; i < n; i++){
        while(uk <= n && temp > k){
            ll x = a[uk];
            r.erase({a[uk], uk});
            temp -= sz(l) - l.order_of_key({x, inf});
            temp -= r.order_of_key({x, 0});
            uk++;
        }
        if(temp > k)break;
        ans += sz(r);
        temp += sz(l) - l.order_of_key({a[i + 1], inf});
        temp += r.order_of_key({a[i + 1], 0});
        l.insert({a[i + 1], i + 1});
    }

    cout << ans << "\n";


    return 0;
}