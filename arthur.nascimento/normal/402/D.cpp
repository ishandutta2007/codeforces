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

int dp[5050][5050];

int primes[5050];

map<int,int> ff;

int n,m;

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;}

int f(int x){

	int y=x;
	if(ff.find(x) != ff.end()){
		return ff[x];
		}

	int ret = 0;
	for(int i=0;i<m;i++)
		while(x > 1 && x%primes[i] == 0){
			ret--;
			x/=primes[i];}

	for(int i=2;i*i<=x;i++)
		while(x > 1 && x%i == 0){
			ret++;
			x/=i;
			}

	if(x > 1)
		ret++;

	ff[y] = ret;

	
	return ret;

}

int F[5050];
int Fgcd[5050];
int pgcd[5050];
int v[5050];

int sumf[5050];

//int val[5050][5050];
int psum[5050][5050];

int getsumf(int a,int b){
	int ret = sumf[b];
	if(a)ret -= sumf[a-1];
	return ret;}

int getsum(int a,int b,int k){
	int ret = psum[k][b];
	if(a)ret -= psum[k][a-1];
	return ret;}

int get(int p,int last){

	if(dp[p][last+1]+1)
		return dp[p][last+1];

	if(p == n)
		return getsumf(last+1,n-1);

	int ret = get(p+1,last);

	ret = max(ret, get(p+1,p) + getsum(last+1,p,p));

	return dp[p][last+1] = ret;

}

main(){

		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);
		for(int i=0;i<m;i++)
			scanf("%d",primes+i);

		for(int i=0;i<n;i++){
			F[i] = f(v[i]);
			debug("F[%d] = %d\n",i,F[i]);
			}

		pgcd[0] = v[0];
		Fgcd[0] = F[0];

		for(int i=1;i<n;i++){
			pgcd[i] = gcd(pgcd[i-1], v[i]);
			Fgcd[i] = f(pgcd[i]);
			}

		//for(int i=0;i<n;i++)
			//for(int j=i;j<n;j++)
				//val[j][i] = F[i] - Fgcd[j];

		for(int i=0;i<n;i++){

			psum[i][0] = (F[0] - Fgcd[i]);

			for(int j=1;j<n;j++)
				psum[i][j] = psum[i][j-1] + (F[j] - Fgcd[i]);

			}

		sumf[0] = F[0];
		for(int i=1;i<n;i++)
			sumf[i] = sumf[i-1] + F[i];

		memset(dp,-1,sizeof(dp));
		printf("%d\n",get(0,-1));

	}