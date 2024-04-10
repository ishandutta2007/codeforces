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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    while(q--){
        ll h, n;
        cin >> h >> n;
        vector <ll> a(n + 2);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(h == 1){
            cout << "0\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            dp[i] = inf;
        }
        ll ans = 0;
        ll last = h;
        ll kol = 0;
        dp[1] = 0;
        for(int i = 1; i < n; i++){
            if(i + 1 <= n)dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            if(i + 2 <= n && a[i + 1] - 1 == a[i + 2])dp[i + 2] = min(dp[i + 2], dp[i]);
        }
        ans = dp[n];
        if(a[n] == 1)ans = min(ans, dp[n - 1]);
        cout << ans << "\n";

    }
    return 0;
}

/*
1
8 6
8 7 6 5 3 2
*/