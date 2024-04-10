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

ll val[MAXN], dp[MAXN], pref[MAXN];

ll get(ll l, ll r){
    if(l > r)return 0;
    return pref[r] - pref[l - 1];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a.begin() + 1, a.end());

    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + a[i];

    reverse(a.begin() + 1, a.begin() + k + 1);

    while(m--){
        ll x, y;
        cin >> x >> y;
        if(x <= k)val[x] = max(val[x], y);
    }

    for(int i = 1; i <= k; i++)dp[i] = 1e18;

    for(int j = k + 1; j > 1; j--){
        for(int i = 1; i <= k; i++)if(j > i){
            ll l = j - i, r = j - 1;
            dp[j - i] = min(dp[j - i], dp[j] + get(l + val[i], r));
        }
    }

    cout << dp[1] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}