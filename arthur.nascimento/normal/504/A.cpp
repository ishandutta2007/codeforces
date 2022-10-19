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
#define maxn 100100

using namespace std;

int pai[maxn];
vector<int> L[maxn];

pii k[maxn];

int foi[maxn];
int pp[maxn];

void dfs(int x,int p){

	if(foi[x])return;
	foi[x] = 1;
	for(vector<int>::iterator it=L[x].begin();it<L[x].end();it++) if(*it!=p){
		dfs(*it,x);
		printf("%d %d\n",x,*it);
	}

}

main(){

		int n;
		scanf("%d",&n);

		queue<int> Q;

		for(int i=0;i<n;i++){
			scanf("%d%d",&k[i].first,&k[i].second);
			if(k[i].first <= 1)
				Q.push(i), pp[i] = 1;
		}

		int m=0;
		
		while(Q.size()){

			int u = Q.front();
			Q.pop();

			if(k[u].first){
				pai[u] = k[u].second;
				L[k[u].second].pb(u);
				debug("add %d %d\n",k[u].second,u);
				m++;
				k[k[u].second].second ^= u;
				k[k[u].second].first--;
				if(k[k[u].second].first == 1 && !pp[k[u].second])
					Q.push(k[u].second), pp[k[u].second] = 1;
			}

		}

		printf("%d\n",m);
		for(int i=0;i<n;i++) if(!foi[i]) dfs(i,i);

}