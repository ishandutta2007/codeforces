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

#define inf (999999999)
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
#define maxn 1001000

using namespace std;

long long F0[maxn+1];
long long F1[maxn+1];
long long F2[maxn+1];
long long S[maxn+1];
long long Q[maxn+1];
long long sum[3][maxn+1];
vector<int> divs[maxn+1];

long long s(long long n){
	return ((n*(n-1))/2)%mod;}
long long s2(long long n){
	return ((n*(n+1)*(2*n+1))/6)%mod;}

main(){

		for(int i=2;i<maxn;i++)
			for(int j=1;i*j<maxn;j++)
				divs[i*j].pb(i);
	
		Q[1] = 2;

		for(int i=2;i<maxn;i++){

			Q[i] = i+1;
			for(vector<int> :: iterator it = divs[i].begin(); it < divs[i].end(); it++)
				Q[i] -= Q[i/(*it)];

		}

		S[1] = 2;

		for(int i=2;i<maxn;i++){

			S[i] = Q[i];
			for(vector<int> :: iterator it = divs[i].begin(); it < divs[i].end(); it++)
				S[i] += *it * Q[i/(*it)];

		}

		for(int i=1;i<maxn;i++){
			F0[i] = s2(i) + s2(i-1) - (long long)i*i*2 + 2*S[i] - 2*i; 
			F0[i] %= mod;
			debug("F[%d] = %I64d\n",i,F0[i]);
			F1[i] = (F0[i] * i)%mod;
			F2[i] = (F1[i] * i)%mod;
			sum[0][i] = (sum[0][i-1] + F0[i])%mod;
			sum[1][i] = (sum[1][i-1] + F1[i])%mod;
			sum[2][i] = (sum[2][i-1] + F2[i])%mod;
		}

		

		int t;
		scanf("%d",&t);
		while(t--){

			long long n,m;
			scanf("%I64d%I64d",&n,&m), n++, m++;

			 if(n < m) swap(n,m);

			 printf("%I64d\n",(((((n*m)%mod)*sum[0][m])%mod - ((n+m)*sum[1][m])%mod + sum[2][m])%mod+mod)%mod);

		}

}