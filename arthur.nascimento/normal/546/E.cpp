#include <iostream>
#include <iomanip>
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

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 1000000007
#define maxn 220

using namespace std;

vector<int> L[maxn];
int cap[maxn][maxn];

int x[maxn];
int y[maxn];

int foi[maxn];
int pai[maxn];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		int sum = 0, sum2 = 0;

		for(int i=0;i<n;i++)
			scanf("%d",x+i), sum += x[i];
		for(int i=0;i<n;i++)
			scanf("%d",y+i), sum2 += y[i];

		for(int i=0;i<n;i++){
			L[i+1].pb(i+1+n);
			L[i+1+n].pb(i+1);
			cap[i+1][i+1+n] = 10000;
			L[0].pb(i+1);
			cap[0][i+1] = x[i];
			L[i+1+n].pb(2*n+1);
			cap[i+1+n][2*n+1] = y[i];
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			L[a].pb(b+n);
			L[b+n].pb(a);
			cap[a][b+n] = 10000;
			L[b].pb(a+n);
			L[a+n].pb(b);
			cap[b][a+n] = 10000;
		}

		int tot = 0;

		while(1){

			memset(foi,0,sizeof(foi));

			queue<int> Q;
			Q.push(0);

			while(Q.size()){

				int u = Q.front();
				Q.pop();

				if(u == 2*n+1) break;

				for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++) if(!foi[*it] && cap[u][*it] != 0){
					foi[*it] = 1;
					pai[*it] = u;
					Q.push(*it);
				}

			}

			if(!foi[2*n+1]) break;

			int flow = 10000;
			int cur = 2*n+1;
			while(cur){
				flow = min(flow,cap[pai[cur]][cur]);
				cur = pai[cur];
			}
			cur = 2*n+1;
			while(cur){
				debug("%d ",cur);
				cap[pai[cur]][cur] -= flow;
				cap[cur][pai[cur]] += flow;
				cur = pai[cur];
			}

			debug("+ %d\n",flow);
			tot += flow;

		}
		
		if(tot != sum || sum != sum2){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",cap[j+1+n][i+1]);
			printf("\n");
		}

}