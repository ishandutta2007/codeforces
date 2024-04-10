#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 400400

typedef long long ll;
using namespace std;

int foi[maxn];
int cur = 0;
vector<pii> L[maxn];
int last[maxn];

int dfs(int v,int tgt,int ch,int pr=0){

	if( pr ==1)
		debug("dfs %d tgt %d ch %d\n",v,tgt,ch);
	int ret = 0;
	foi[v] = cur;
	last[v] = ch;
	if(ch) ret++;
	if(pr && ch)
		printf("%d ",v+1);
	for(int i=0;i<L[v].size();i++){
		int u = L[v][i].first, cor = L[v][i].second;
		if(foi[u] == cur){
			if( (cor^last[v]^last[u]) != tgt) ret = maxn;
		}
		else 
			ret += dfs(u,tgt,last[v]^tgt^cor,pr);
	}
	return ret;
}

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){
		int a,b,c;
		char ch;
		scanf("%d%d %c",&a,&b,&ch), a--, b--;
		c = (ch == 'R') ? 1 : 0;
		L[a].pb(pii(b,c));
		L[b].pb(pii(a,c));
	}

	int ans0 = 0, ans1 = 0;

	for(int i=0;i<n;i++)
		if(!foi[i]){
			cur++;
			int A0 = dfs(i,0,0);
			debug("dfs %d %d -> %d\n",0,0,A0);
			cur++;
			int B0 = dfs(i,0,1);
			debug("dfs %d %d -> %d\n",0,1,B0);
			A0 = min(A0,B0);
			cur++;
			int A1 = dfs(i,1,0);
			debug("dfs %d %d -> %d\n",1,0,A1);
			cur++;
			int B1 = dfs(i,1,1);
			debug("dfs %d %d -> %d\n",1,1,B1);
			A1 = min(A1,B1);
			ans0 += A0;
			ans1 += A1;
			if(ans0 > maxn) ans0 = maxn;
			if(ans1 > maxn) ans1 = maxn;
		}

	if(ans0 >= maxn && ans1 >= maxn){
		printf("-1\n");
		return 0;
	}

	int u = (ans0 < ans1) ? 0 : 1;

	memset(foi,0,sizeof(foi));
	cur = 0;

	printf("%d\n",min(ans0,ans1));

	for(int i=0;i<n;i++)
		if(!foi[i]){
			cur++;
			int A0 = dfs(i,u,0);
			cur++;
			int A1 = dfs(i,u,1);
			cur++;
			if(A0 < A1)
				dfs(i,u,0,1);
			else
				dfs(i,u,1,1);

		}

}