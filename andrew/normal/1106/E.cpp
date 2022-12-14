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

const ll N = 1e5 + 10;

vector <pll> v[MAXN], v1[MAXN];

ll dp[N][201];

multiset <pll> s;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("complexity.in","r",stdin);
    //freopen("complexity.out","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m; j++)dp[i][j] = 1e18;

    dp[0][0] = 0;

    for(int i = 1; i <= k; i++){
        ll s, t, d, w;
        cin >> s >> t >> d >> w;
        v[s].p_b({w, d});
        v1[t + 1].p_b({w, d});
    }

    for(int i = 1; i <= n; i++){
        for(auto j : v[i])s.insert(j);
        for(auto j : v1[i])s.erase(s.find(j));
        multiset <pll> :: iterator it;

        ll d, w;

        if(s.empty()){
            d = i;
            w = 0;
        }else{
            it = s.end();
            --it;
            w = it -> fi;
            d = it -> se;
        }
        for(int j = 0; j <= m; j++){
            if(j < m)dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
            dp[d][j] = min(dp[d][j], dp[i - 1][j] + w);
        }
    }

    ll ans = 1e18;

    for(int i = 0; i <= m; i++)ans = min(ans, dp[n][i]);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}