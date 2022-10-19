#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int v[55];

int dp[55][500500];
int n;

int get(int p,int vmax){
    
    if(dp[p][vmax]+1)
                     return dp[p][vmax];
                     
    if(p == n)
         return 0;
         
    int ret = get(p+1,vmax);
    
    if(v[p] <= vmax)
            ret = max(ret, v[p] + get(p+1,vmax-v[p]));
    
    return dp[p][vmax] = ret;
         
}

main(){
       
       int d;
       scanf("%d%d",&n,&d);
       
       for(int i=0;i<n;i++)
               scanf("%d",v+i);
               
       int val = 0;
       int ans = 0;
       
       memset(dp,-1,sizeof(dp));
       
       while(1){
                int last = val;
                val = get(0,val+d);
                if(val == last)
                       break;
                ans++;
                }
       
       printf("%d %d\n",val,ans);
       
}