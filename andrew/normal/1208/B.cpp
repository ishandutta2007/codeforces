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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> a(n + 1), le(n + 1), suf(n + 2), suf1(n + 2), ri(n + 1);

    map <ll, ll> mp, mp1;

    ll ans = 1e18;

    bool good = 1;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = i;
            mp1[a[i]] = i;
            le[i] = 1e18;
            ri[i] = 0;
        }else{
            good = 0;
            ri[i] = mp1[a[i]];
            le[i] = mp[a[i]];
            mp1[a[i]] = i;
        }
    }

    if(good)vout(0);

    suf[n + 1] = 1e18;

    for(int i = n; i > 0; i--){
        suf[i] = min(suf[i + 1], le[i]);
        suf1[i] = max(suf1[i + 1], ri[i]);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)if((suf[j + 1] >= i && suf1[j + 1] <= j) || suf[j + 1] == 1e18){
            ans = min(ans, ll(j - i + 1));
            break;
        }
        if(le[i] < i)break;
    }

    vout(ans);


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}