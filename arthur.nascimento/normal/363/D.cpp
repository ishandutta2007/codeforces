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

int v[100100];
int p[100100];

main(){

		int n,m,g;
		scanf("%d%d%d",&n,&m,&g);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);
		for(int i=0;i<m;i++)
			scanf("%d",p+i);

		sort(v,v+n);
		sort(p,p+m);

		int a=0,b=min(n,m);

		while(a != b){

			int t = (a+b+1)/2;

			int k = g;

			for(int i=0;i<t && k>=0;i++){
				if(v[i+n-t] < p[i])
					k -= p[i] - v[i+n-t];
				}

			if(k >= 0)
				a = t;
			else
				b = t-1;

			}

		for(int i=0;i<a;i++)
			g -= p[i];

		printf("%d %d\n",a,max(0,-g));

}