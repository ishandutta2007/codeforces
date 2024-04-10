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

#define mod 1000000007

using namespace std;

int v[1001000];
long long l[1001000];
long long r[1001000];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int cont = 0;
		long long qnt = 0;
		long long sum = 0;

		for(int i=0;i<n;i++){

			if(i)
				sum += qnt*(v[i]-v[i-1]);
		
			l[i] = sum;

			if(cont == 0)
				cont = m-1,
				qnt++;
			else
				cont--;
				
			}

		cont = 0;
		qnt = 0;
		sum = 0;

		for(int i=n-1;i>=0;i--){

			if(i != n-1)
				sum += qnt*(v[i+1]-v[i]);

			r[i] = sum;

			if(cont == 0)
				cont = m-1,
				qnt++;
			else
				cont--;
				
			}

		long long ans = l[0]+r[0];

		for(int i=1;i<n;i++)
			ans = min(ans,l[i]+r[i]);

		printf("%I64d\n",2*ans);

}