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

ll MOD = 998244353;

void f(ll &a, ll b){a = (a + b) % MOD;}

ll dp[1001][4][2200];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, k;
    cin >> n >> k;

    dp[1][0][1] = 1;
    dp[1][1][2] = 1;
    dp[1][2][2] = 1;
    dp[1][3][1] = 1;

    for(int i = 2; i <= n; i++){
        for(int old_kom = 1; old_kom <= k; old_kom++){

                f(dp[i][0][old_kom], dp[i - 1][0][old_kom]);
                f(dp[i][1][old_kom + 1], dp[i - 1][0][old_kom]);
                f(dp[i][2][old_kom + 1], dp[i - 1][0][old_kom]);
                f(dp[i][3][old_kom + 1], dp[i - 1][0][old_kom]);


                f(dp[i][0][old_kom], dp[i - 1][1][old_kom]);
                f(dp[i][1][old_kom], dp[i - 1][1][old_kom]);
                f(dp[i][2][old_kom + 2], dp[i - 1][1][old_kom]);
                f(dp[i][3][old_kom], dp[i - 1][1][old_kom]);


                f(dp[i][0][old_kom], dp[i - 1][2][old_kom]);
                f(dp[i][1][old_kom + 2], dp[i - 1][2][old_kom]);
                f(dp[i][2][old_kom], dp[i - 1][2][old_kom]);
                f(dp[i][3][old_kom], dp[i - 1][2][old_kom]);

                f(dp[i][0][old_kom + 1], dp[i - 1][3][old_kom]);
                f(dp[i][1][old_kom + 1], dp[i - 1][3][old_kom]);
                f(dp[i][2][old_kom + 1], dp[i - 1][3][old_kom]);
                f(dp[i][3][old_kom], dp[i - 1][3][old_kom]);
        }
    }

    ll ans = 0;
    for(int i = 0; i < 4; i++)f(ans, dp[n][i][k]);
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}