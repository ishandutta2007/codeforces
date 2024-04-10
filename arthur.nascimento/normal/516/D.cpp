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

int T[maxn];

void update(int idx,int val){
	idx++;
	while(idx < maxn){
		T[idx] += val;
		idx += (idx&-idx);
	}
}

int query(int idx){
	int ret = 0;
	idx++;
	while(idx){
		ret += T[idx];
		idx -= (idx&-idx);
	}
	return ret;
}

vector<pii> L[maxn];
int par[maxn];
long long sobe[maxn];

long long dm;
int ponta;

void dfs0(int x,int p,long long d){
	debug("dfs0 %d\n",x);
	if(d > dm){
		dm = d;
		ponta = x;
	}
	par[x] = p;
	for(vector<pii> :: iterator it =  L[x].begin(); it < L[x].end(); it++) if(it->first != p)
		dfs0(it->first,x,d+it->second), sobe[it->first] = it->second;
}

int pre[maxn];
int fim[maxn];

vector<pll> v;
int cont;

void dfs(int x,int p,long long d){
	pre[x] = cont++;
	fim[x] = pre[x];
	v.pb(pll(d,x));
	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(it->first != p){
		dfs(it->first,x,d+it->second);
		fim[x] = fim[it->first];
	}
}

int dfs2(int x,int p,long long dc,long long dm){
	if(dc > dm) return 0;
	int ret = 1;
	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(it->first != p)
		ret += dfs2(it->first,x,dc+it->second,dm);
	return ret;
}

main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int a,b,p;
			scanf("%d%d%d",&a,&b,&p), a--, b--;
			L[a].pb(pii(b,p));
			L[b].pb(pii(a,p));
		}

		dm = 0;
		dfs0(0,0,0);
		dm = 0;
		int p1 = ponta;
		dfs0(p1,p1,0);
		int p2 = ponta;
		debug("p = %d %d\n",p1,p2);
		long long dcur = 0;
		int r2 = p2;
		while( 2LL*(dcur + sobe[r2]) < dm){	
			dcur += sobe[r2];
			r2 = par[r2];
		}
		int r1 = par[r2];

		long long d1 = dcur + sobe[r2];
		long long d2 = dm - d1 + sobe[r2]; 

		debug("r = %d(%I64d) %d(%I64d)\n",r1,d1,r2,d2);

		dfs(r1,r2,d1);
		dfs(r2,r1,d2);

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		int q;
		scanf("%d",&q);

		while(q--){

			long long k;
			scanf("%I64d",&k);

			memset(T,0,sizeof(T));
			for(int i=0;i<n;i++)
				update(i,1);

			int ptr = 0;

			int ans = 1;

			for(int i=0;i<n;i++){
				while(v[ptr].first - v[i].first > k){
					update(pre[v[ptr].second],-1);
					ptr++;
				}
				ans = max(ans,query(fim[v[i].second])-query(pre[v[i].second]-1));
			}

			ans = max(ans, dfs2(r1,r2,d1,min(d1,d2)+k) + dfs2(r2,r1,d2,min(d1,d2)+k));

			printf("%d\n",ans);

		}

}