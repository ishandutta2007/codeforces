#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
#define all(x) x.begin(),x.end()

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
ll dp[MAXN][4];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
   string s[2];
   cin >> s[0] >> s[1];
   n = s[0].size();
   vector <ll> ans(n);
   for(int i = 0; i < n; i++)ans[i] = 0;
   for(int i = 0; i < 2; i++){
                         for(int j = 0; j < n; j++){
                                                  char cc;
                                                  cc = s[i][j];
                                                  if(cc == 'X')ans[j] |= 1ll << i;
                         }     
   }
   for(int i = 0; i < n; i++)for(int j = 0; j < 4; j++)dp[i][j] = -1e18;
   dp[0][ans[0]] = 0;
   //cout << ans[7] << endl;
   for(int i = 0; i < n - 1; i++){
                         for(int j = 0; j < 4; j++)if(dp[i][j] != -1e18){
                                                  //cout << i << " " << j << " " << dp[i][j] << endl;
                                                  dp[i + 1][ans[i + 1]] = max(dp[i][j], dp[i + 1][ans[i + 1]]);
                                                  ll a = (1 & j), b = (2 & j);
                                                  for(int i1 = 0; i1 < 4; i1++){
                                                     ll mask = i1 | ans[i + 1];
                                                     ll a1 = (1 & mask), b1 = (2 & mask);
                                                     if(a == 0 && b == 0 && a1 == 0)dp[i + 1][mask | 1] = max(dp[i + 1][mask | 1], dp[i][j] + 1);
                                                     if(a == 0 && b1 == 0 && a1 == 0)dp[i + 1][3] = max(dp[i + 1][3], dp[i][j] + 1);
                                                     if(b == 0 && b1 == 0 && a1 == 0)dp[i + 1][3] = max(dp[i + 1][3], dp[i][j] + 1);
                                                     if(a == 0 && b == 0 && b1 == 0)dp[i + 1][mask | 2] = max(dp[i + 1][mask | 2], dp[i][j] + 1);
                                                  } 
                         }                         
   }
   ll res = 0;
   for(int i = 0; i < 4; i++)res = max(res, dp[n - 1][i]);
   cout << res << endl;
   return 0;
 }