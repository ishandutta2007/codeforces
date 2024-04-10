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

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

using namespace std;

int v[maxn];
int phi[maxn];
int dp[160][maxn];
int dp2[160][maxn];

int big[maxn];
int top[maxn];	

int gcd[maxn];

int id[maxn];

int get2(int d,int t){
	if(dp2[id[d]][t]+1)
		return dp2[id[d]][t];
	if(t == 0) return 0;
	return dp2[id[d]][t] = get2(d,t-1) + ((gcd[t] == d) ? 1 : 0);
}

int get(int d,int t){
	if(dp[id[d]][t]+1)
		return dp[id[d]][t];
	if(t == 0) return 0;
	return dp[id[d]][t] = get(d,t-1) + get2(d,t);
}

main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
	
	phi[0] = 0;
	for(int i=1;i<=n;i++){
		phi[i] = phi[i-1];
		if(__gcd(i,n) == 1)
			phi[i]++;
	}
	
	for(int i=1;i<=n;i++)
		gcd[i] = __gcd(i,n);
	
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	
	long long ans = 0;
	int p = 0;
	
	for(int i=1;i<n;i++)
		if(n%i == 0){
			debug("i=%d\n",i);
			id[i] = p++;
			memset(big,0,sizeof(big));
			memset(top,0,sizeof(top));
			for(int j=0;j<n;j++)
				big[j%i] = max(big[j%i],v[j]);
			int cnt = 0;
			for(int j=0;j<n;j++)
				if(v[j] == big[j%i]){
					top[j] = 1, cnt++;
					debug("top %d\n",j);
				}
			if(cnt == n){
				debug("+ %d\n",n);
				ans += (long long) get2(i,n) * n;
			}
			else {	
				int t = 0;
				int u = n-1;
				while(top[u]){
					t++;
					u--;
				}
				for(int j=0;j<n;j++){
					if(top[j]) t++;
					else {
						ans += get(i,t);
						debug("+ %d\n",t);
						t = 0;
					}
				}
			}
		}
	
	cout << ans << endl;
	
}