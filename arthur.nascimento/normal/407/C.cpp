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
#define maxn 100100
#define mod 1000000007

using namespace std;

int init[maxn];
long long fat[2*maxn];

int v[110][maxn];

int dp[101100][105];

inline int C(int n,int k){
	if(k > n) return 0;
	if(k == n) return 1;
	if(k == 0) return 1;
	if(n == 0) return 0;
	if(dp[n][k]+1) return dp[n][k];
	return dp[n][k] = (C(n-1,k) + C(n-1,k-1)) % mod;
}

char ch;
int ret;
int read(){
	ret = 0;
	while((ch=getchar()) >= '0')
		ret = 10*ret+ch-'0';
	return ret;
}

main(){

	memset(dp,-1,sizeof(dp));
	
	int n,m;
	//scanf("%d%d",&n,&m);
	n = read();
	m = read();
	
	for(int i=0;i<n;i++){
		init[i] = read();
		//scanf("%d",init+i);
	}
		
	fat[0] = 1;
	for(int i=1;i<2*maxn;i++)
		fat[i] = (fat[i-1]*i) % mod;
		
	while(m--){
		int l,r,k;
		//scanf("%d%d%d",&l,&r,&k), l--, r--;
		l = read()-1;
		r = read()-1;
		k = read();
		v[k+1][l]++;
		v[k+1][l+1]--;
		for(int i=0;i<=k;i++){
			v[i][r+1] -= C(k+r-l-i,k-i);
			if(v[i][r+1] < 0) v[i][r+1] += mod;
		}
	}
	
	for(int i=101;i>=0;i--)
		for(int j=0;j<n;j++){
			v[i][j] += v[i+1][j];
			if(v[i][j] > mod) v[i][j] -= mod;
			if(j) {
				v[i][j] += v[i][j-1];
				if(v[i][j] > mod) v[i][j] -= mod;
			}
		}
		
	for(int i=0;i<n;i++)
		printf("%d ",(v[0][i]+init[i])%mod);
	printf("\n");
	
}