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

#define max3(a,b,c) max(max(a,b),c)

using namespace std;

long long v[100100];
long long pos[100100];

int n,m;

long long best(long long pi,long long pf,long long t){

	if(pf >= pi)
		return pi+t;

	if(t < pi-pf)
		return -1;

	return max3(pi, 2*pf + t - pi, (t+pi+pf)/2);

}

int ok(long long t){

	int p = 0;

	for(int i=0;i<n && p < m;i++){

		long long x = best(v[i], pos[p], t);

		if(x == -1)
			return 0;

		while(pos[p] <= x && p < m)
			p++;

		}

	if(p != m)
		return 0;
	return 1;

}

main(){

		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i);

		for(int i=0;i<m;i++)
			scanf("%I64d",pos+i);

		sort(v,v+n);
		sort(pos,pos+m);

		long long a=0, b=20000000000LL;

		while(a != b){

			long long M = (a+b)/2;

			if(ok(M))
				b = M;
			else
				a = M+1;

		}

		printf("%I64d\n",a);

}