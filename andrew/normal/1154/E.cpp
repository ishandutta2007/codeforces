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

vector <ll> ans, a;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;

    a.resize(n);
    ans.resize(n);

    set <ll> pos;
    set <pll> d;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= -1;
        pos.insert(i);
        d.insert({a[i], i});
    }

    for(int step = 0; step <= n; step++){
        if(pos.empty())break;
        ll vall = 1;
        if(step % 2)vall = 2;
        pll xe = *d.begin();
        d.erase(d.begin());
        pos.erase(xe.se);
        ans[xe.se] = vall;

        set <ll> :: iterator it;
        for(int i = 0; i < k; i++){
            it = pos.lower_bound(xe.se);
            if(it == pos.end())break;
            ll val = *it;
            d.erase({a[val], val});
            pos.erase(val);
            ans[val] = vall;
        }

        for(int i = 0; i < k; i++){
            it = pos.lower_bound(xe.se);
            if(it == pos.begin())break;
            --it;
            ll val = *it;
            d.erase({a[val], val});
            pos.erase(val);
            ans[val] = vall;
        }

    }

    for(auto i : ans)cout << i;
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}