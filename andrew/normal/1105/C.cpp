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

const ll MOD = 1e9 + 7;

ll dp[MAXN][3];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;

    vector <ll> o(3);

    ll l, r;
    cin >> n >> l >> r;

    while(l <= r && l % 3){
        o[l % 3]++;
        l++;
    }

    if(l <= r){
        ll kol = r - l + 1;
        for(int i = 0; i < 3; i++)o[i] += kol / 3;

        for(int i = 0; i < kol % 3; i++)o[i]++;
    }


    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int old = 0; old < 3; old++)
        for(int j = 0; j < 3; j++){
            dp[i][(old + j) % 3] += dp[i - 1][old] * o[j];
            dp[i][(old + j) % 3] %= MOD;
        }
    }

    cout << dp[n][0] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}