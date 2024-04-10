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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007

using namespace std;

int tem[2020];
int v[2020];
long long fat[2020];

long long exp2(int a,int b){

	if(b == 0)
		return 1;
	if(b == 1)
		return a;

	long long k = exp2(a,b/2);
	k = (k*k)%mod;

	if(b%2)
		k = (k*a)%mod;

	return k;

	}

long long inv(int n){
	return exp2(n,mod-2);}

long long C(int n,int k){
	return (fat[n] * inv((fat[k]*fat[n-k])%mod))%mod;
}

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",v+i);
		if(v[i]+1)
			tem[v[i]-1] = 1;
		}

	int m=0,k=0;

	for(int i=0;i<n;i++){

		if(v[i] == -1){
			m++;
			if(!tem[i])
				k++;
		}}

	fat[0] = 1;

	for(int i=1;i<=n;i++)
		fat[i] = (i*fat[i-1])%mod;

	long long resp = fat[m];
	int sinal = -1;

	
	for(int i=1;i<=k;i++){

		resp = (resp + ((sinal * C(k,i) * fat[m-i])%mod+mod)%mod)%mod;
		
		sinal *= -1;
		}

	printf("%I64d\n",resp);

	}