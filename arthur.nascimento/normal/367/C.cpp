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

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
 
using namespace std;

struct bla {
	int custo,aa;
	bool operator<(bla comp)const{
		return custo > comp.custo;}
	};

bla v[100100];

int f[2200];

main(){

		for(int i=1;i<2100;i++)
			if(i%2)
				f[i] = 1+(i*i-i)/2;
			else
				f[i] = (i/2)+(i*i-i)/2;


		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++)
			scanf("%d%d",&v[i].aa,&v[i].custo);

		sort(v,v+m);

		int k = 1;

		for(int i=1;i<2100;i++)
			if(f[i] <= n)
				k = max(k,i);

		long long ans = 0;

		for(int i=0;i<n && i < k;i++)
			ans += v[i].custo;

		printf("%I64d\n",ans);

	}