#include <bits/stdc++.h>
#define maxn 400400
#define pii pair<int,int>
#define pb push_back
#define inf 1e9
#define mod 998244353
typedef long long ll;
using namespace std;

int dp[2020][2020];

int n,m;

int get(int pos,int df){
    if(df < 0) return 0;
    if(pos == n){
        if(df == 0) return 1;
        return 0;
    }
    if(dp[pos][df]+1)
        return dp[pos][df];
    ll ans = (ll) get(pos+1,df) + (ll) (m-1) * get(pos+1,df-1);
   // printf("%d %d %lld\n",pos,df,ans%mod);
    return dp[pos][df] = ans%mod;
}


int main() {
    int k;
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,-1,sizeof(dp));
    ll ans = get(1,k);
    ans *= m;
    ans %= mod;
    printf("%lld\n",ans);
}