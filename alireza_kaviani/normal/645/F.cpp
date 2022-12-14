/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll MAXM = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , k , q , ans , mark[MAXN] , fact[MAXN] , inv[MAXN] , A[MAXN] , cnt[MAXN] , dp[8][MAXN];
vector<ll> D[MAXN] , P[MAXN];

ll C(ll r , ll n){
    if(r > n || r < 0 || n < 0) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void insert(ll x){
    for(ll i : D[x]){
        dp[SZ(P[x])][i] = C(k - 1 , cnt[i]);
        cnt[i]++;
        for(ll j = SZ(P[x]) - 1 ; j >= 0 ; j--){
            dp[j][i] = (dp[j + 1][i] - (i * P[x][j] > x ? 0 : dp[j + 1][i * P[x][j]]) + MOD) % MOD;
        }
        ans = (ans + dp[0][i] * i) % MOD;
    }
    for(ll i : D[x]){
        //cout << i << sep;
        for(ll j = 0 ; j < 8 ; j++){
            //cout << dp[j][i] << sep;
            dp[j][i] = 0;
        }
        ///cout << endl;
    }
    //cout << ans << endl;
    //cout << "===========" << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for(ll i = 1 ; i < MAXM ; i++)  fact[i] = fact[i - 1] * i % MOD;
    for(ll i = 0 ; i < MAXM ; i++)  inv[i] = poww(fact[i] , MOD - 2 , MOD);

    for(ll i = 1 ; i < MAXN ; i++){
        ll A = mark[i];
        for(ll j = i ; j < MAXN ; j += i){
            mark[j] |= (i != 1);
            D[j].push_back(i);
            if(A == 0 && i != 1)    P[j].push_back(i);
        }
    }
    for(ll i = 0 ; i < MAXN ; i++)  reverse(all(D[i]));

    cin >> n >> k >> q;
    for(ll i = 1 ; i <= n ; i++){
        cin >> A[i];
        insert(A[i]);
    }

    while(q--){
        ll x;
        cin >> x;
        insert(x);
        cout << ans << endl;
    }

    return 0;
}
/*

*/