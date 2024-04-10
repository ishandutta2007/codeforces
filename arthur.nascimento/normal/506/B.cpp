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

vector<int> L[maxn];
vector<int> L2[maxn];
vector<int> L3[maxn];

int ans = 0;

int foi[maxn];
int foi2[maxn];
int cc[maxn];

vector<int> T[maxn];

void dfs(int x,int u){
	if(foi[x])return;
	foi[x] = 1;
	for(vector<int> :: iterator it = L2[x].begin(); it < L2[x].end(); it++)
		dfs(*it,u);
	cc[x] = u;
	debug("%d %d\n",x,u);
	T[u].pb(x);
}



int indg[maxn];
int foi4[maxn];
int get(int x){
	foi2[cc[x]] = 1;
	int a = cc[x];

	queue<int> Q;
	for(int i=0;i<T[a].size();i++)
		if(indg[T[a][i]] == 0)
			Q.push(T[a][i]);
	while(Q.size()){
		int y = Q.front();
		Q.pop();
		debug("y=%d\n",y);
		foi4[y]++;
		for(vector<int> :: iterator it = L[y].begin(); it < L[y].end(); it++){
			indg[*it]--;
			debug("-- %d %d\n",*it,indg[*it]);
			if(indg[*it] == 0)
				Q.push(*it);
		}
	}
	int ok = 1;
	for(int i=0;i<T[a].size();i++)
		if(!foi4[T[a][i]]) ok = 0;
	if(ok)
		return T[a].size()-1;
	else
		return T[a].size();

}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L2[a].pb(b);
			L2[b].pb(a);
			indg[b]++;
		}

		int cur = 0;
		for(int i=0;i<n;i++) if(!foi[i]){
			dfs(i,cur); cur++;}
			

		for(int i=0;i<n;i++) if(!foi2[cc[i]])
			ans += get(i);
			
		printf("%d\n",ans);

}