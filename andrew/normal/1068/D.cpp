#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;
const ll MOD = 998244353;

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

ll dp[100000 + 2][201][2];

ll p[MAXN], p1[MAXN];

ll pref[MAXN][2];

void f(ll &a, ll b){a = (a + b) % MOD;}

ll get(ll v, ll l, ll r){
    ll res = pref[r][v] - pref[l - 1][v];
    while(res < 0)res += MOD;
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];

    if(a[1] == -1){
        for(int i = 1; i <= 200; i++)dp[1][i][1] = 1;
    }else{
        dp[1][a[1]][1] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 200; j++){
            pref[j][0] =  pref[j - 1][0] + dp[i - 1][j][0];
            pref[j][0] %= MOD;
            pref[j][1] = pref[j - 1][1] + dp[i - 1][j][1];
            pref[j][1] %= MOD;
        }
        if(a[i] == -1){
            for(int j = 1; j <= 200; j++){
                if(i == 2){
                    ll r = j;
                    ll x = j;
                    if(j != 1)f(dp[i][x][1], get(1, 1, j - 1));
                    f(dp[i][x][0], get(1, j, j));
                    if(j != 1)f(dp[i][x][1], get(0, 1, j - 1));
                    continue;
                }
                if(i == n){
                    ll x = j;
                    f(dp[i][x][0], get(1, j, j));
                    f(dp[i][x][0], get(0, j, 200));
                    continue;
                }
                ll x = j;
                if(j != 1)f(dp[i][x][1], get(1, 1, j - 1));
                f(dp[i][x][0], get(1, j, j));
                f(dp[i][x][0], get(0, j, 200));
                if(j != 1)f(dp[i][x][1], get(0, 1, j - 1));
            }
        }else{
            if(i == 2){
                ll j = a[i];
                ll r = j;
                ll x = j;
                if(j != 1)f(dp[i][x][1], get(1, 1, j - 1));
                f(dp[i][x][0], get(1, j, j));
                if(j != 1)f(dp[i][x][1], get(0, 1, j - 1));
                continue;
            }
            if(i == n){
                ll j = a[i];
                ll x = j;
               // cout << get(1, j, j) << " " << get(0, j, 200) << "\n";
                f(dp[i][x][0], get(1, j, j));
                f(dp[i][x][0], get(0, j, 200));
                continue;
            }
            ll x = a[i];
            ll j = x;
            if(j != 1)f(dp[i][x][1], get(1, 1, j - 1));
            f(dp[i][x][0], get(1, j, j));
            f(dp[i][x][0], get(0, j, 200));
            if(j != 1)f(dp[i][x][1], get(0, 1, j - 1));
        }
    }
    ll ans = 0;
    for(int i = 1; i <= 200; i++)f(ans, dp[n][i][0]);
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}