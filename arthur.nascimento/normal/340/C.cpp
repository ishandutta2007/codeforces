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

long long gcd(long long a,long long b){
	return b ? gcd(b,a%b) : a;}

int v[100100];

main(){

		int n;
		scanf("%d",&n);

		long long sum = 0;

		for(int i=0;i<n;i++)
			scanf("%d",v+i), sum += v[i];

		long long S = 0;

		sort(v,v+n);

		for(int i=0;i<n;i++)
			S += v[i]-v[0];

		for(int i=0;i<n;i++){
			sum += S*2;
			S -= (long long)(v[i+1]-v[i]) * (n-i-1);
		}

		
		long long d = gcd(sum,n);

		printf("%I64d %I64d\n",sum/d,n/d);


	}