#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct line{
    ll l, r;

    line(ll le, ll ri): l(le), r(ri){}

    void merge(line b){
        l = max(l, b.l);
        r = min(r, b.r);
    }
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <pll> a(n);
        vector <ll> f1(n), f2(n), f3(n), f4(n);
        line x = *new line(-1e5, 1e5);
        line y = *new line(-1e5, 1e5);

        for(int i = 0; i < n; i++){
            cin >> a[i].fi >> a[i].se;
            cin >> f1[i] >> f2[i] >> f3[i] >> f4[i];
            ll le = -1e5, ri = 1e5;
            if(!f1[i])le = a[i].fi;
            if(!f3[i])ri = a[i].fi;
            x.merge(*new line(le, ri));
            le = -1e5, ri = 1e5;
            if(!f4[i])le = a[i].se;
            if(!f2[i])ri = a[i].se;
            y.merge(*new line(le, ri));
        }

        if(x.l > x.r || y.l > y.r)cout << "0\n"; else{
            cout << "1 " << x.l << " " << y.l << "\n";
        }


    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}