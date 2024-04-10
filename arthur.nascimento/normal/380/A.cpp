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

long long sz[100100];
int T[100100];
int A[100100];
int B[100100];

int ans[100100];

pll r[100100];

main(){


		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){

			int t;
			scanf("%d",&t);

			if(t == 1){

					if(i == 0)
						sz[i] = 1;
					else
						sz[i] = 1 + sz[i-1];

					int a;
					scanf("%d",&a);

					if(sz[i] <= 100000)
						v[sz[i]-1] = a;

					T[i] = t;
					A[i] = a;
					
					}

			else {

					int a,b;
					scanf("%d%d",&a,&b);

					sz[i] = sz[i-1];

					for(long long j=sz[i]; j < 100000 && j < sz[i] + a*b; j++)
						v[j] = v[(j-sz[i]) % a];

					sz[i] = sz[i-1] + a*b;

					T[i] = t;
					A[i] = a;
					B[i] = b;

				}


			}

		int q;
		scanf("%d",&q);

		for(int i=0;i<q;i++)
			scanf("%I64d",&r[i].first),
			r[i].first--,
			r[i].second = i;

		sort(r,r+q);

		int p = 0;

		for(int i=0;i<q;i++){

			while(sz[p] < r[i].first+1)
				p++;

			debug("i=%d p=%d sz=%d\n",i,p,sz[p]);

			if(T[p] == 1)
				ans[r[i].second] = A[p];

			else
				ans[r[i].second] = v[(r[i].first - sz[p-1]) % A[p]];


			}

		for(int i=0;i<q;i++)
			printf("%d ",ans[i]);

			}