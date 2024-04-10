#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector <pll> c;

    ll q;
    cin >> q;

    ll kek = pw(32) - 1;
    ll S = 0, p = 1;

    while(q--){
        string t;
        cin >> t;
        if(t == "for"){
            ll x;
            cin >> x;
            c.p_b({x, p});
            p = min(p * x, kek + 2);
        }else if(t == "end"){
            p = c.back().se;
            c.pop_back();
        }else{
            S += p;
            if(S > kek)vout("OVERFLOW!!!");
        }
    }

    cout << S << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}