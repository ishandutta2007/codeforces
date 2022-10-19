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

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int left = 0;

		for(int i=0;i<31;i++){
		
			int q = 0;
			for(int j=0;j<n;j++)
				if(v[j] & (1<<i))
					q++;

			if(q != 0 && q != n)
				left = i;


		}

		int ans = 0;

		for(int i=0;i<n;i++)
			if(v[i] & (1<<left)){

				int m = 0;

				for(int j = i+1;j<n && (v[j] & (1<<left)) == 0; j++)
					m = max(m,v[j]),
					ans = max(ans, v[i] ^ m);

				m = 0;
				for(int j=i-1;j>=0 && (v[j] & (1<<left)) == 0; j--)
					m = max(m,v[j]),
					ans = max(ans, v[i] ^ m); 


				}

		printf("%d\n",ans);


	}