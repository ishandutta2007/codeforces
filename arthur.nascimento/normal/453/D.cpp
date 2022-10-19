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

#define inf (9999999999999999LL)
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
#define mod 1000000007
#define maxn (1<<20)
#define sq(x) ((x)*(x))	

using namespace std;

int m,p;
int n;

long long b[22];
long long e[maxn];

int dp[2][21][maxn];

void calc(){

	for(int i=0;i<n;i++)
		dp[1][0][i] = e[i];

	for(int i=0;i<m;i++) 
		for(int k=0;k<=m && k <= i+1;k++)
			for(int j=0;j<n;j++)
				dp[i&1][k][j] = (dp[1-(i&1)][k][j] + (k?dp[1-(i&1)][k-1][j^(1<<i)]:0)) % p;

	memset(e,0,sizeof(e));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<=m;j++)
			e[i] = (b[j] * dp[1-(m&1)][j][i] + e[i]) % p;

}			

long long dp2[65][22];
long long v[22][22][22];
long long aux[22];

main(){

		long long t;
		scanf("%d%I64d%d",&m,&t,&p);

		n = 1 << m;

		for(int i=0;i<=m;i++){
			int tgt = (1<<i) - 1;
			for(int j=0;j<n;j++)
				v[i][__builtin_popcount(j)][__builtin_popcount(j^tgt)]++;
		}	

		for(int i=0;i<n;i++)
			scanf("%I64d",e+i);
		for(int i=0;i<=m;i++)
			scanf("%I64d",b+i);

		for(int i=0;i<=m;i++)
			dp2[0][i] = b[i];

		for(int i=1;i<64;i++)
			for(int j=0;j<=m;j++)
				for(int k=0;k<=m;k++)
					for(int l=0;l<=m;l++)
						dp2[i][j] = (dp2[i][j] + (v[j][k][l] * (dp2[i-1][k] * dp2[i-1][l]%p)%p))%p;

		int f = 1;
		for(int i=0;i<64;i++) if(t & (1LL<<i)){
			if(f){
				f = 0;
				for(int j=0;j<=m;j++) b[j] = dp2[i][j];
				continue;
			}
			memset(aux,0,sizeof(aux));
			for(int j=0;j<=m;j++)
				for(int k=0;k<=m;k++)
					for(int l=0;l<=m;l++)
						aux[j] = (aux[j] + (v[j][k][l] * (dp2[i][k] * b[l]%p)%p))%p;
			for(int j=0;j<=m;j++)
				b[j] = aux[j];
		}

		for(int i=0;i<=m;i++)
			debug("%I64d ",b[i]);
		debug("\n");

		//while(t--)
			calc();

		for(int i=0;i<n;i++)
			printf("%I64d\n",e[i]);

}