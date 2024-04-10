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
#define maxn 1010			
#define mod 1000000007
 
using namespace std;

int dp[2][155][155*155];

int v[155];

main(){
	
		int n,k,s;
		scanf("%d%d%d",&n,&k,&s);
		
		vector<pii> u;
		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			u.pb(pii(v[i],i));
		}
		
		sort(u.begin(),u.end());
		
		vector<int> y;
		for(int i=0;i<k;i++)
			y.pb(u[i].second);
			
		sort(y.begin(),y.end());
		
		int cur = 0,sum = 0;
		
		for(int i=0;i<k;i++)
			cur += y[i]-i, sum += u[i].first;
		
		if(cur <= s){
			printf("%d\n",sum);
			return 0;
		}
		
		for(int i=n;i>=0;i--)
			for(int j=0;j<=s;j++)
				for(int l=0;l<=k;l++){
					
					if(l == k){
						dp[i&1][l][j] = 0;
						continue;
					}
					if(i == n){
						dp[i&1][l][j] = 999999999;
						continue;
					}
					dp[i&1][l][j] = dp[(i+1)&1][l][j];
					if(j >= i-l) dp[i&1][l][j] = min(dp[i&1][l][j], v[i]+dp[(i+1)&1][l+1][j-(i-l)]);
					
					//debug("dp %d %d %d = %d\n",i,l,j,dp[i][l][j]);
		
				}
				
		printf("%d\n",dp[0][0][s]);
		
}