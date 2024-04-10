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
#define maxn 200200
#define mod 1000000007

using namespace std;

vector<int> L[maxn];
int mrk[maxn];
int dist[2][maxn];
int tira[maxn];
int dg[maxn];

void dfs(int x,int p,int d,int idx){
	dist[idx][x] = d;
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(*it != p && !tira[*it])
		dfs(*it,x,d+1,idx);
}

main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
		dg[a]++;
		dg[b]++;
	}
	while(m--){
		int u;
		scanf("%d",&u), u--;
		mrk[u] = 1;
	}
	queue<int> Q;
	for(int i=0;i<n;i++) if(dg[i] == 1 && !mrk[i]) Q.push(i);
	int E = -1;
	while(Q.size()){
		int u = Q.front();
		Q.pop();
		tira[u] = 1;
		for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++) if(!tira[*it] && !mrk[*it]){
			dg[*it]--;
			if(dg[*it] == 1) Q.push(*it);
		}
	}
	int r = n-1;
	for(int i=n-1;i>=0;i--)
		if(!tira[i]) r = i, E++;
	dfs(r,r,0,0);
	int s = r;
	for(int i=0;i<n;i++)
		if(dist[0][i] > dist[0][s])
			s = i;
	dfs(s,s,0,1);
	int dm = 0;
	for(int i=0;i<n;i++) {
		if(dist[1][i] > dm)
			dm = dist[1][i], s = i;
	}
	dfs(s,s,0,0);
	int ans = 0;
	while(tira[ans]) ans++;
	for(int i=0;i<n;i++) if(!tira[ans] && max(dist[0][i],dist[1][i]) > max(dist[0][ans],dist[1][ans])) ans = i;
	printf("%d\n%d\n",1+ans,2*E-dm);
}