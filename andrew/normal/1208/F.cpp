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

struct Set{
    ll a, b;

    void insert(ll x){
        if(x > a)a = x;
        if(a > b)swap(a, b);
    }
};

Set clr;
Set s[5 * MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    clr.b = clr.a = -1e18;

    for(int i = 0; i < 5 * MAXN; i++)s[i] = clr;

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[a[i]].insert(i);
    }

    for(int i = 0; i <= 21; i++){
        for(int j = pw(21) - 1; j >= 0; j--)if((j & pw(i))){
            s[j ^ pw(i)].insert(s[j].a);
            s[j ^ pw(i)].insert(s[j].b);
        }
    }

    ll ans = 0;

    for(int st = 21; st >= 0; st--){
        ll mb = ans | pw(st);
        bool ok = 0;

        for(int i = 1; i <= n; i++){
            ll us = mb ^ (mb & a[i]);
            if(s[us].a > i){
                ok = 1;
                break;
            }
        }

        if(ok)ans = mb;
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}