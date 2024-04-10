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

#define inf (9999999999999999LL)
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
#define maxn 10100

using namespace std;

struct obj {
	int c,v,t;
	obj(int c=0,int v=0,int t=0): c(c), v(v), t(t) {}
	bool operator<(obj comp) const{
		return t < comp.t;
	}
}

V[maxn];

struct query {
	int t,c,idx;
	bool operator<(query comp) const{
		return t < comp.t;
	}
}

Q[20200];
int ans[20200];

int n,k;

int dp[2][4040][4040];

int i0[10100];

int get(int ord,int pos,int v,int g){

	if(v < 0) return -999999999;
	if(pos == -1 || pos == n) return 0;
	if(V[pos].t/k != g) return 0;

	if(dp[ord][pos][v]+1)
		return dp[ord][pos][v];

	int next = pos+1;
	if(ord) next = pos-1;

	return dp[ord][pos][v] = max(get(ord,next,v,g), get(ord,next,v-V[pos].c,g) + V[pos].v);

}

main(){

		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d%d%d",&V[i].c,&V[i].v,&V[i].t);

		sort(V,V+n);

		for(int i=n-1;i>=0;i--)
			i0[V[i].t/k] = i;

		int q;
		scanf("%d",&q);

		for(int i=0;i<q;i++)
			scanf("%d%d",&Q[i].t,&Q[i].c), Q[i].idx = i, Q[i].t -= k-1;

		sort(Q,Q+q);

		memset(dp,-1,sizeof(dp));

		int p=0, p2=0;

		for(int i=0;i<q;i++){

			while(p < n && V[p].t < Q[i].t) p++;
			while(p2 < n-1 && V[p2+1].t < Q[i].t+k) p2++;

			if(p == n) continue;
			if(V[p].t >= Q[i].t+k) continue;

			int g = V[p].t/k;
			int g2 = V[p2].t/k;

			debug("%d-%d\n",p,p2);

			if(g == g2){
				if(p != i0[g]) ans[Q[i].idx] = get(0,p,Q[i].c,g);
				else ans[Q[i].idx] = get(1,p2,Q[i].c,g);
				//else ans[Q[i].idx] = get(0,p,Q[i].c,g);
				continue;
			}


			for(int j=0;j<=Q[i].c;j++)
				ans[Q[i].idx] = max(ans[Q[i].idx], get(0,p,j,g) + get(1,p2,Q[i].c-j,g2));

		}

		for(int i=0;i<q;i++)
			printf("%d\n",ans[i]);

}