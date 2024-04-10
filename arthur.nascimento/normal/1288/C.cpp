#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug 
#define mk make_pair
#define pii pair<int,int>
#define mod 1000000007 
using namespace std;

int dp[12][1010];

int get(int sz,int mx){
    int &r = dp[sz][mx];
    if(r+1) return r;
    if(sz == 0) return (r=1);
    r = 0;
   
    for(int i=mx;i>=1;i--){
        r = (r + get(sz-1,i)) % mod;
    }
    debug("dp %d %d = %d\n",sz,mx,r);
    return r;

}

main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            
            ans += (ll) get(m-1,i) * get(m-1,n-j+1);
            ans %= mod;
        }
        
    printf("%lld\n",ans);
}