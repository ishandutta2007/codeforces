#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define hash sosat

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll va, vb, vc;
    cin >> va >> vb >> vc;

    ll ans = 0;

    for(int i = 1; i <= 7; i++){
        ll l = 1, r = 3e9;

        while(l < r){
            ll c = (l + r) >> 1;
            if(c == l)c++;
            ll kol = c / 7, va1 = va, vb1 = vb, vc1 = vc, day = i;
            va1 -= 3 * kol;
            vb1 -= 2 * kol;
            vc1 -= 2 * kol;
            ll ost = c % 7;
            for(int j = 0; j < ost; j++){
                if(day == 1 || day == 4 || day == 7)va1--; else if(day == 2 || day == 6)vb1--; else vc1--;
                day++;
                if(day == 8)day = 1;
            }
            if(va1 < 0 || vb1 < 0 || vc1 < 0)r = c - 1; else l = c;
        }

        ans = max(ans, l);

    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}