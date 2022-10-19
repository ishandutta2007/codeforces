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
#include <complex>

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
#define maxn 2*1100000
#define mod 1000000007

using namespace std;

int v[1010];

int dp[1010][1010];

long long C(int n,int k){
    if(n == k) return 1;
    if(k > n) return 0;
    if(k == 0) return 1;
    if(dp[n][k]+1) return dp[n][k];
    return dp[n][k] = (C(n-1,k-1) + C(n-1,k)) % mod;
}

main(){ 

        memset(dp,-1,sizeof(dp));
        
        int k;
        int n=0;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",v+i);
            n += v[i];
        }
        
        long long ans = 1;
        
        for(int i=k-1;i>=0;i--){
            
            v[i]--;
            n--;
            ans *= C(n,v[i]);
            n -= v[i];
            ans %= mod;
            
        }
        
        cout << ans << endl;
        
}