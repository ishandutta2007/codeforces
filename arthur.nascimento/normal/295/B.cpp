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

int peso[550][550];
int dist[550][550];

int v[550];

stack<long long>s;

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i != j)
					dist[i][j] = 999999999;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&peso[i][j]);

		for(int i=0;i<n;i++)
			scanf("%d",v+i), v[i]--;

		for(int k=n-1;k>=0;k--){

			for(int i=n-1;i>=k;i--)
				for(int j=n-1;j>=k;j--)
					dist[v[i]][v[k]] = min(dist[v[i]][v[k]], dist[v[i]][v[j]] + peso[v[j]][v[k]]),
					dist[v[k]][v[i]] = min(dist[v[k]][v[i]], peso[v[k]][v[j]] + dist[v[j]][v[i]]);
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dist[i][j] = min(dist[i][j],dist[i][v[k]]+dist[v[k]][j]);

			long long sum = 0;

			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(dist[i][j] != 999999999)
						sum += dist[i][j];

			s.push(sum);


		}

		while(s.size())
			printf("%I64d ",s.top()), s.pop();

	}