#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

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
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

map < ll, vector <pll> > mp;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    ll n;
    cin >> n;

    vector <pll> ans;

    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++){
        ll sc = 0;
        for(int j = i; j <= n; j++){
            sc += a[j];
            mp[sc].p_b({j, i});
        }
    }

    for(auto i : mp){
        vector <pll> d = i.se;
        sort(all(d));
        ll l = 0;
        vector <pll> c;
        for(auto i : d){
            if(i.se > l){
                c.p_b({i.se, i.fi});
                l = i.fi;
            }
        }
        if(c.size() > ans.size()){
            ans = c;
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans)cout << i.fi << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}