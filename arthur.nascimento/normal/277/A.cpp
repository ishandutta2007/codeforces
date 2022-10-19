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
#define maxn 110
#define mod 1000000007

typedef long long ll;
using namespace std;

int has[maxn][maxn];
int k[maxn];
vector<int> L[maxn];

int foi[maxn];

void dfs(int v){
	if(foi[v]) return;
	foi[v] = 1;
	for(int i=0;i<L[v].size();i++)
		dfs(L[v][i]);
}

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	int y = 0;

	for(int i=0;i<n;i++){
		debug("i=%d\n",i);
		scanf("%d",k+i);
		if(k[i]) y = 1;
		for(int j=0;j<k[i];j++){
			int u;
			scanf("%d",&u), u--;
			has[i][u] = 1;
		}
	}

	if(y == 0){
		printf("%d\n",n);
		return 0;
	}

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			debug("%d %d\n",i,j);
			int ok = 0;
			for(int l=0;l<m;l++)
				if(has[i][l] && has[j][l])
					ok = 1;
			if(ok){
				L[i].pb(j);
				L[j].pb(i);
			}
		}

	debug("oi");

	int ans = -1;
	for(int i=0;i<n;i++)
		if(!foi[i]){
			dfs(i);
			ans++;
		}

	printf("%d\n",ans);

}