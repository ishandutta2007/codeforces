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
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[555][555];
bool f[555][555];

string s;

ll sol(ll l, ll r){
    if(l > r)return 0;
    if(f[l][r])return dp[l][r];
    f[l][r] = 1;
    if(l == r){
        dp[l][r] = 1;
        return 1;
    }

    dp[l][r] = inf;

    for(int i = l; i < r; i++)dp[l][r] = min(dp[l][r], sol(l, i) + sol(i + 1, r));

    for(int i = l + 1; i <= r; i++)if(s[i] == s[l]){
        dp[l][r] = min(dp[l][r], sol(l + 1, i - 1) + sol(i, r));
    }

    return dp[l][r];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;

    cin >> s;

    cout << sol(0, n - 1) << "\n";

    return 0;
}