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

#define mod 1000000007 

int logp[100100];

long long v[100100];
long long m[100100];

long long exp(long long a,long long b){

	if(b==0)
		return 1;
	if(b==1)
		return a;

	long long k = exp(a,b/2);
	k=(k*k)%mod;

	if(b%2)
		k=(k*a)%mod;
	return k;
}

main(){

		int n;
		long long p;
		scanf("%d%I64d",&n,&p);

		for(int i=0;i<n;i++)
			m[i] = 1;

		memset(logp,-1,sizeof(logp));
		long long k = p;
		for(int i=1;k<=100000;i++){
			for(long long j=1;k*j <= 100000;j++)
					logp[k*j] = i;
			k *= p;
		}


		long long sum = 0;

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i),
			sum += v[i];

		for(int i=0;i<n;i++)
			v[i] = sum - v[i];

		sort(v,v+n);

		long long ans = 0;

		int u = 0;

		multiset<pll> S;

		for(int i=0;i<n;i++)
			S.insert(pll(v[i],1));

		while(u < n){


			int q = 0;
			int M = 0;
		//	while(u+q < n && v[u+q] == v[u])
			//	M += m[u+q],
				//q++;

			long long e = (S.begin()) -> first;

			debug("e = %I64d\n",e);

			if(S.size() == 1){
				ans = e;
				break;}
			
			
			for(multiset<pll> :: iterator it = S.begin(); it != S.end() && it->first == e;){
				M += it -> second;
				assert(M <= 100000);
				q++;
				it++;
				S.erase(S.begin());}

			ans = e;

			

			if(logp[M] == -1)
				break;

			//u += q-1;
			//v[u] = logp[M];
			debug("log %d %d\n",M,v[u]);
			//m[u] = M / exp(p,logp[M]);
			assert(M%exp(p,logp[M]) == 0);
			S.insert(pll(logp[M]+ans,M/exp(p,logp[M])));
		}

		printf("%I64d\n",exp(p,min(ans,sum)));

	}