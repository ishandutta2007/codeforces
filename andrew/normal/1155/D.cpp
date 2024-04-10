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
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll dp[MAXN][3];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, x;
    cin >> n >> x;
    vector <ll> a(n + 1);

    ll mn = 0, s = 0, ans = 0;;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][0] = max(0ll, max(dp[i - 1][0] + a[i] * x, s - mn + a[i] * x));
        dp[i][1] = max(max(dp[i - 1][1] + a[i], dp[i - 1][0] + a[i]), 0ll);
        dp[i][1] = max(dp[i][1], s - mn + a[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
        s += a[i];
        mn = min(mn, s);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}