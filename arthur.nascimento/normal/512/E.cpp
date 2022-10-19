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
#define maxn 1010
#define mod 1000000007

using namespace std;

int beg[maxn][maxn];
int tgt[maxn][maxn];

vector<pii> ans;

void solve(int a,int b){

	int u;
	debug("solve %d %d\n",a,b);
	if(b==a+1)return;
	if(beg[a][b]){
		ans.pb(pii(a,b));
		u=b-1;
		while(beg[a][u] == 0 && u > a+1)u--;
		solve(a,u);
		solve(u,b);
		return;
	}

	u = a+1;
	while(beg[1][u] == 0)u++;
	solve(a,u);
	solve(u,b);

}

void solve2(int a,int b){

	int u;
	if(b==a+1)return;
	if(tgt[a][b]){
		u=b-1;
		while(tgt[a][u] == 0 && u > a+1)u--;
		ans.pb(pii(1,u));
		solve2(a,u);
		solve2(u,b);
		return;
	}

	u = a+1;
	while(tgt[1][u] == 0)u++;
	solve2(a,u);
	solve2(u,b);

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n-3;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			beg[a][b] = beg[b][a] = 1;
		}
		for(int i=0;i<n-3;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			tgt[a][b] = tgt[b][a] = 1;
		}


		solve(2,n);
		vector<pii> t = ans;
		ans.clear();
		solve2(2,n);
		reverse(ans.begin(),ans.end());

		printf("%d\n",ans.size()+t.size());

		for(int i=0;i<t.size();i++)
			printf("%d %d\n",t[i].first,t[i].second);
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);

}