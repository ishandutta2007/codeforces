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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int n,k,d;

int mrk[100100];
vector<int> L[100100];

int pai[100100];
int filho[100100];
int achou[100100];
int best[100100][2];

int ans = 0;

void dfs(int x,int p){

	achou[x] = 1;
	pai[x] = p;

	best[x][0] = best[x][1] = -999999;

	if(mrk[x]){
		best[x][0] = 0;
		filho[x] = x;
	}

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!achou[*it]){
			dfs(*it,x);

			if(best[*it][0] + 1 > best[x][0]){
				filho[x] = *it;
				best[x][1] = best[x][0];
				best[x][0] = best[*it][0] + 1;
				}
			else if(best[*it][0] + 1 > best[x][1])
				best[x][1] = best[*it][0] + 1;

			
		}

	debug("best[%d] = %d\n",x,best[x][0]);	

}

void dfs2(int x){

	achou[x] = 1;

	if(x){
		int p = (x == filho[pai[x]]) ? 1 : 0;
	
		if(best[pai[x]][p] + 1 > best[x][0]){
				filho[x] = pai[x];
				best[x][1] = best[x][0];
				best[x][0] = best[pai[x]][p] + 1;
				}
			else if(best[pai[x]][p] + 1 > best[x][1])
				best[x][1] = best[pai[x]][p] + 1;

		}

	if(best[x][0] <= d){
		ans++;
		debug("%d\n",x);

	}

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!achou[*it])
			dfs2(*it);


}

main(){

	scanf("%d%d%d",&n,&k,&d);

	for(int i=0;i<k;i++){
		int a;
		scanf("%d",&a);
		mrk[a-1] = 1;
		}

	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		L[a-1].push_back(b-1);
		L[b-1].push_back(a-1);
		}

	dfs(0,0);
	memset(achou,0,sizeof(achou));
	dfs2(0);

	printf("%d\n",ans);
	
	}