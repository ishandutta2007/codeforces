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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    set <ll> s;
    map <ll, ll> mp;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        mp[x]++;
        s.insert(x);
    }

    vector <ll> mb;
    for(int i = 1; i <= m; i++){
        ll x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(y == 1e9)continue;
        if(x1 != 1)continue;
        mb.p_b(x2);
    }

    sort(all(mb));
    ll sc = 0;
    ll ans = 1e18;
    ll kol = 0;
    if(s.size()){
        set <ll> :: iterator it = s.begin(), it1;
        for(; it != s.end(); ++it){
            ll con = 1e9;
            con = *it;
            ll l = lower_bound(all(mb), con) - mb.begin();
            ans = min(sc + mb.size() - l, ans);
            //cout << mb.size() << " " << l << endl;
            sc += mp[*it];
        }
    }
    ll con = 1e9;
    ll l = lower_bound(all(mb), con) - mb.begin();
    ans = min(sc + mb.size() - l, ans);
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}