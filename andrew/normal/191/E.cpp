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
#define pii pair<int,int>
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

vector <ll> a, pref;
ll n;

ll f(ll k){
    ordered_set <pll> s;

    s.insert({0ll, 0ll});

    ll res = 0;

    for(int i = 1; i <= n; i++){
        res += s.order_of_key({pref[i] - k, 1e9});
        s.insert({pref[i], i});
    }
    return res;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;

    a.resize(n + 1);
    pref.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    ll l = -1e15, r = 1e15;

    while(l < r){
        ll c = (l + r) >> 1;
        if(f(c) >= k)l = c + 1; else r = c;
    }

    if(f(l) < k)l--;

    cout << l << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}