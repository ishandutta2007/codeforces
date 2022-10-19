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

#define inf 99999999999.
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

int dp[20][maxn][11];
int pai[20][maxn];
int tam[20][maxn];
int prof[maxn];
int ff[maxn][11];

vector<int> beg[maxn];

vector<int> L[maxn];

int res[25];
int tres;
void merge(int *pa,int ta,int *pb,int tb){
	debug("merge ");
	int ra=0, rb=0;
	int ans = 0;
	tres = ta+tb;
	while(ra != ta || rb != tb){
		if(ra == ta)
			res[ans++] = pb[rb++];
		else if(rb == tb)
			res[ans++] = pa[ra++];
		else if(pa[ra] < pb[rb])
			res[ans++] = pa[ra++];
		else	
			res[ans++] = pb[rb++];
	}
	debug("ok\n");
}

void dfs(int x,int p){

	if(1){
		if(x) prof[x] = 1 + prof[p];
		pai[0][x] = p;
		tam[0][x] = min(10,(int)beg[x].size());
		for(int i=0;i<tam[0][x];i++)
			dp[0][x][i] = beg[x][i];
		if(x) for(int i=1;i<20;i++){
			pai[i][x] = pai[i-1][pai[i-1][x]];
			tam[i][x] = min(10,tam[i-1][x]+tam[i-1][pai[i-1][x]]);
			merge(dp[i-1][x],tam[i-1][x],dp[i-1][pai[i-1][x]],tam[i-1][pai[i-1][x]]);
			for(int j=0;j<tam[i][x];j++)
				dp[i][x][j] = res[j];
		}
	}
	

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(*it != p){
		dfs(*it,x);
	}

}

int ans[12];
int len;

inline void print(){return;
	debug("%d -> ",len);
	for(int i=0;i<len;i++)
		debug("%d ",ans[i]);
	debug("\n");
}

void lca(int a,int b){

	if(prof[a] > prof[b])
		swap(a,b);

	len = 0;
	
	int dh = prof[b]-prof[a];
	for(int i=0;i<20;i++)
		if(dh & (1<<i)){
			merge(dp[i][b],tam[i][b],ans,len);
			debug("+ [%d;%d)\n",b,pai[i][b]);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			b = pai[i][b];
			print();
		}

	if(a == b){
		merge(ans,len,ff[a],min(10,(int)beg[a].size()));
		len = min(10,tres);
		for(int j=0;j<len;j++)
			ans[j] = res[j];
		debug("+%d\n",a);
		print();
		return;
	}

	for(int i=19;i>=0;i--)
		if(pai[i][a] != pai[i][b]){
			debug("+ [%d;%d)\n",b,pai[i][b]);
			merge(dp[i][b],tam[i][b],ans,len);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			print();
			merge(dp[i][a],tam[i][a],ans,len);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			
			debug("+ [%d;%d)\n",a,pai[i][a]);
			print();
			a = pai[i][a];
			b = pai[i][b];
		}

	debug("+ [%d;%d)\n",b,pai[0][b]);
			merge(dp[0][b],tam[0][b],ans,len);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			print();
			merge(dp[0][a],tam[0][a],ans,len);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			
			debug("+ [%d;%d)\n",a,pai[0][a]);
			print();
			a = pai[0][a];
			b = pai[0][b];

//	a = pai[0][a];
	debug("+%d\n",a);
	merge(dp[0][a],tam[0][a],ans,len);
			len = min(10,tres);
			for(int j=0;j<len;j++)
				ans[j] = res[j];
			print();
	return;

}

main(){

		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		for(int i=0;i<m;i++){
			int u;
			scanf("%d",&u);
			beg[u-1].pb(i+1);
		}

		for(int i=0;i<n;i++)
			sort(beg[i].begin(),beg[i].end());
		for(int i=0;i<n;i++)
			for(int j=0;j<min(10,(int)beg[i].size());j++)
				ff[i][j] = beg[i][j];

		dfs(0,0);

		for(int i=0;i<q;i++){
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t), a--, b--;
			lca(a,b);
			printf("%d",min(t,len));
			for(int j=0;j<min(t,len);j++)
				printf(" %d",ans[j]);
			printf("\n");
		}

}