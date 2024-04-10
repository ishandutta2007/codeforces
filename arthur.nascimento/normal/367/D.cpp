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
int bad[2002000];
int foi[2002000];

int qnt[1001000];

int n,m,d;

void dfs(int x){

	bad[x] = foi[x] = 1;
	debug("dfs %d\n",x);

	for(int i=0;i<m;i++)
		if((x&(1<<i)) == 0 && !foi[x|(1<<i)])
			dfs(x|(1<<i));

}

main(){

		
		scanf("%d%d%d",&n,&m,&d);

		for(int i=0;i<m;i++){
		
			int k;
			scanf("%d",&k);

			while(k--){

				int a;
				scanf("%d",&a);

				v[a-1] = 1<<i;

			}

		}

		int s = 0;

		for(int i=0;i<d;i++)
			if(++qnt[v[i]] == 1)
				s += v[i];

		for(int i=0;i+d<=n;i++){

			bad[s] = 1;
			
			debug("+ %d\n",s);

			if(++qnt[v[i+d]] == 1)
				s += v[i+d];

			if(--qnt[v[i]] == 0)
				s -= v[i];
				
		}

		for(int i=0;i<(1<<m);i++)
			if(bad[i] && !foi[i])
				dfs(i);

		int ans = m;

		for(int i=0;i<(1<<m);i++){

			int t = m;
			for(int j=0;j<m;j++)
				if(i&(1<<j))
					t--;

			if(!bad[i])
				ans = min(ans, t);

		}

		printf("%d\n",ans);

}