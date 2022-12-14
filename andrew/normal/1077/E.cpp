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

map <ll, ll> mp;


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    multiset <ll> s;
    while(n--){
        ll x;
        cin >> x;
        mp[x]++;
    }

    for(auto i : mp)s.insert(i.se);
    ll ans = 0;
    ll N = 3e5;
    multiset <ll> :: iterator it;
    for(int i = 1; i <= N; i++){
        ll sc = 0;
        vector <ll> a;
        ll x = i;
        while(s.lower_bound(x) != s.end()){
            sc += x;
            it = s.lower_bound(x);
            a.p_b(*it);
            s.erase(it);
            x *= 2;
        }
        ans = max(ans, sc);
        for(auto j : a)s.insert(j);
    }
    vout(ans);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}