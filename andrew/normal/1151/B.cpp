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
const ll MOD = 1e9 + 7;

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
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

bool dp[1001][21][2];

pll pr[1001][21][2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < 11; i++)dp[0][i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ll x;
            cin >> x;
            for(int i1 = 0; i1 < 11; i1++){
                for(int bit = 0; bit < 2; bit++)if(dp[i - 1][i1][bit]){
                    ll to = bit;
                    if((x & (1ll << i1)))to ^= 1;
                    dp[i][i1][to] = 1;
                    pr[i][i1][to] = {j, bit};
                }
            }
        }
    }

    ll ans = -1;
    for(int i = 0; i < 11; i++)if(dp[n][i][1])ans = i;
    if(ans == -1)vout("NIE");
    vector <ll> pans;
    ll bit = 1;
    for(int i = n; i > 0; i--){
        pans.p_b(pr[i][ans][bit].fi);
        bit = pr[i][ans][bit].se;
    }

    reverse(all(pans));
    cout << "TAK\n";
    for(auto i : pans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}