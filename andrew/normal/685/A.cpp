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
#define delete kek_void

using namespace std;
using namespace __gnu_pbds;
typedef int ll;
typedef long double ld;
const ll MAXN = 1323456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll kol[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    if(n > 1e6 || m > 1e6)vout(0);

    ll len = 0;

    ll x = m - 1;

    while(x){
        len++;
        x /= 7;
    }

    if(m == 1)len++;

    for(int i = 0; i < m; i++){
        ll musk = 0, Kol = 0;
        ll val = 0, x = i;

        while(x){
            Kol++;
            musk |= pw(x % 7);
            x /= 7;
        }

        if(Kol < len){
            musk |= pw(0ll);
        }

        if(__builtin_popcount(musk) == len){
            kol[musk]++;
        }
    }


    len = 0, x = n - 1;
    ll ans = 0;

    while(x){
        len++;
        x /= 7;
    }

    if(n == 1)len++;

    for(int i = 0; i < n; i++){
        ll musk = 0, Kol = 0;
        ll val = 0, x = i;

        while(x){
            Kol++;
            musk |= pw(x % 7);
            x /= 7;
        }

        if(Kol < len){
            musk |= pw(0ll);
        }

        if(__builtin_popcount(musk) == len){
            for(int j = 0; j < 200; j++)if(!(musk & j))ans += kol[j];
        }
    }

    cout << ans << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}