#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define pll pair<ll, ll>
#define m_p make_pair
#define p_b push_back
#define all(v) v.begin(), v.end()
#define sqr(x)  (x) * (x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 3e5 + 5;
const ll M = 20;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll dp[111][111], f[N][30];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    ll n, q;
    cin >> n >> q;
    vector <ll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)dp[i][j] = 1e18;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < M; j++)f[i][j] = 1e18;

        for(int j = 0; j < M; j++)if((pw(j) & a[i])){
            f[i][j] = i;
            for(int k = 0; k < M; k++)f[i][k] = min(f[i][k], dp[j][k]);
        }

        for(int j = 0; j < M; j++)if((pw(j) & a[i])){
            for(int k = 0; k < M; k++)dp[j][k] = min(dp[j][k], f[i][k]);
        }

    }

    while(q--){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll ans = 1e18;
        for(int i = 0; i < M; i++)if((a[y] & pw(i)))ans = min(ans, f[x][i]);
        if(ans <= y)cout << "Shi\n"; else cout << "Fou\n";
    }

    return 0;
}