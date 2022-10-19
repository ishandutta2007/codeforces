#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 4040
#define mod 1000000007
 
using namespace std;

int dp[2][maxn];
int dp2[maxn][maxn];

long long C(int n,int k){
    if(k == 0) return 1;
    if(k > n) return 0;
    if(n == 0) return 0;
    if(dp2[n][k]+1) 
        return dp2[n][k];
     long long ret = dp2[n][k] = (C(n-1,k-1) + C(n-1,k)) % mod;
     return ret;
}

int get(int foi,int n){
   
    if(n == 0) return foi; 
    if(dp[foi][n]+1)
        return dp[foi][n];
   long long ret = get(1,n-1)%mod;
   for(int i=0;i<=n-1;i++){
        ret += (C(n-1,i) * get(foi,n-i-1)) % mod;
        ret %= mod;
   }
   
   return dp[foi][n] = ret;
        
}

main(){
    
        int n;
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        printf("%d\n",get(0,n));
        
}