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
#define mod 1000000007
#define maxn 100100

using namespace std;

int T[maxn];

void update(int idx,int val){
	idx++;
	while(idx < maxn){
		T[idx] += val;
		idx += idx&-idx;
	}
}

int query(int idx){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}


int gets(int x,int y){
	int r = query(y);
	if(x) r -= query(x-1);
	return r;
}

int dp[20][maxn];

int get(int a,int k){
	for(int i=0;i<20;i++)
		if(k & (1<<i))
			a = dp[i][a];
	return a;
}

vector<int> L[maxn];


int A[maxn];
int B[maxn];
int prof[maxn];
int cont;

int dfs(int x,int p){
	debug("dfs %d %d\n",x,p);
	if(x)
		prof[x] = 1 + prof[p];
	dp[0][x] = p;
	A[x] = B[x] = cont++;
	for(int i=1;i<20;i++)
		dp[i][x] = dp[i-1][dp[i-1][x]];
	for(int i=0;i<L[x].size();i++)
		if(L[x][i] != p)
			B[x] = dfs(L[x][i],x);
	return B[x];
}

int mapa[maxn];
int foi[maxn];
int pai[maxn];

vector<int> L2[maxn];

int mrk[maxn];
int dp2[2][maxn];

int solve(int f,int v){
	if(dp2[f][v]+1)
		return dp2[f][v];
	if(mrk[v] == 1 && f == 0)
		return 999999;
	debug("get %d %d\n",f,v);
	vector<pii> u;
	int qnt = L2[v].size();
	for(int i=0;i<qnt;i++)
		u.pb(pii(solve(0,L2[v][i]),solve(1,L2[v][i])));
	int ret = 999999;
	if(f){
		int t = 1;
		for(int i=0;i<qnt;i++)
			t += u[i].second;
		if(!mrk[v])
			ret = min(ret,t);
		if(mrk[v]){
			t = 0;
			for(int i=0;i<qnt;i++)
				t += u[i].first;
			debug("dp[%d][%d] = %d\n",f,v,t);
			return dp2[f][v] = t;
		}
		int best = 0;
		for(int i=0;i<qnt;i++)
			best = min(best,u[i].second-u[i].first);
		t = best;
		for(int i=0;i<qnt;i++)
			t += u[i].first;
		ret = min(ret,t);
		debug("dp[%d][%d] = %d\n",f,v,ret);
		return dp2[f][v] = ret;
	}
	else {
		int t = 1;
		for(int i=0;i<qnt;i++)
			t += u[i].second;
		if(!mrk[v])
			ret = min(ret,t);
		t = 0;
		for(int i=0;i<qnt;i++)
			t += u[i].first;
		ret = min(ret,t);
		debug("dp[%d][%d] = %d\n",f,v,ret);
		return dp2[f][v] = ret;
	}
}

map<pii,int> adj;

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
		adj[pii(a,b)] = adj[pii(b,a)] = 1;
	}

	debug("ok\n");
	dfs(0,0);
	debug("ok\n");

	int q;
	scanf("%d",&q);
	int cur = 0;
	
	while(q--){
		debug("oi\n");
		int sz = 0;
		cur++;
		vector<int> v;
		int m;
		int ok = 1;
		scanf("%d",&m);
		
		for(int i=0;i<m;i++){
			int u;
			scanf("%d",&u), u--;
			v.pb(u);
			update(A[u],1);
			mapa[u] = i;
			foi[u] = cur;
		}
		sz = m;

		queue<int> Q;

		vector<int> used;

		int rt;

		for(int i=0;i<m;i++)
			Q.push(v[i]), used.pb(v[i]);

		while(Q.size()){

			int p = Q.front();
			debug("go %d\n",p);
			Q.pop();

			int a = 0, b = prof[p];

			while(a != b){
				int mid = (a+b)/2;
				debug("mid %d\n",mid);
				int r = get(p,mid);
				if(gets(A[r],B[r]) > gets(A[p],B[p]))
					b = mid;
				else
					a = mid+1;
			}

			a = get(p,a);
			int add = 0;
			debug("pai[%d] = %d\n",p,a);
			pai[p] = a;
			if(!foi[a])
				mapa[a] = sz++;
			if(adj[pii(a,p)] && mapa[a] < m && mapa[p] < m){
				ok = 0;debug("bad\n");
			}
			if(mapa[a] < m && mapa[p] < m && a != p && ok){
				int novo = dp[0][p];
				mapa[novo] = sz++;
				L2[mapa[a]].pb(mapa[novo]);
				L2[mapa[novo]].pb(mapa[p]);
				debug("! %d -> %d\n",mapa[a],mapa[novo]);
				debug("! %d -> %d\n",mapa[novo],mapa[p]);
				add = 1;
			}

			if(p == a)
				rt = a;
			else if(!add){
				L2[mapa[a]].pb(mapa[p]);
				debug("%d -> %d\n",mapa[a],mapa[p]);
			}

			if(!foi[a])
				Q.push(a), used.pb(a);
			foi[a] = 1;

		}

		for(int i=0;i<sz;i++)
			dp2[0][i] = dp2[1][i] = -1;
		for(int i=0;i<m;i++)
			mrk[i] = 1;

		int ans = solve(1,mapa[rt]);

		for(int i=0;i<sz;i++)
			L2[i].clear();
		if(!ok)
			printf("-1\n");
		else
			printf("%d\n",ans);
		for(int i=0;i<m;i++)
			update(A[v[i]],-1);
		for(int i=0;i<m;i++)	
			mrk[i] = 0;
		for(int i=0;i<used.size();i++)
			foi[used[i]] = 0;
	}

}