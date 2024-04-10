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

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int A[maxn];
int B[maxn];

vector<int> L[maxn];

int T[maxn];

int prof[maxn];

void update(int idx,int t){
	idx++;
	while(idx < maxn){
		T[idx] += t;
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

int dp[20][maxn];

int cnt;
void dfs(int x,int p){
	if(x)
		prof[x] = 1 + prof[p];
	dp[0][x] = p;
	for(int i=1;i<20;i++)
		dp[i][x] = dp[i-1][dp[i-1][x]];
	A[x] = B[x] = cnt++;
	for(int i=0;i<L[x].size();i++)
		if(L[x][i] != p)
			dfs(L[x][i],x), B[x] = B[L[x][i]];
}

int n,k;

int sobe(int v,int k){
	for(int i=0;i<20;i++)
		if(k & (1<<i))
			v = dp[i][v];
	return v;
}

int part(int v,int u){
	if(query(A[v]) != query(A[v]-1))
		return 1;
	if(query(n) != query(B[v]) - query(A[v]-1) && query(B[v]) != query(A[v]-1))
		return 1;
	if(query(B[v]) == query(A[v]-1))
		return 0;
	u = sobe(u,prof[u]-prof[v]-1);
	if(query(n) == query(B[u]) - query(A[u]-1))
		return 0;
	return 1;
}

int lca(int a,int b){
	if(prof[a] > prof[b])
		swap(a,b);
	int dh = prof[b]-prof[a];
	for(int i=0;i<20;i++)
		if(dh & (1<<i))
			b = dp[i][b];
	if(a == b)
		return a;
	for(int i=19;i>=0;i--)
		if(dp[i][a] != dp[i][b])
			a = dp[i][a], b = dp[i][b];
	return dp[0][a];
}
	

int check(int v,int u){

	debug("check %d %d\n",v,u);
	if(part(v,u))
		return 0;

	int l = lca(v,u);
	int d1 = prof[v]-prof[l];
	int d2 = prof[u]-prof[l];

	int low = 0, up = d1+d2;

	while(low != up){
		int mid = (low+up)/2;
		int r = v;
		if(mid <= d1)
			r = sobe(r,mid);
		else
			r = sobe(u,d2-mid+d1);
		if(part(r,u))
			up = mid;
		else
			low = mid+1;
	}

	return low;

}

main(){

	scanf("%d%d",&n,&k);

	for(int i=1,a,b;i<n;i++)
		scanf("%d%d",&a,&b), a--, b--, L[a].pb(b), L[b].pb(a);

	dfs(0,0);

	int l=0, r=0;
	int ans = 1;
	int cur = 1;
	update(A[0],1);

	while(r != n-1){

		debug("add %d\n",r+1);
		cur += check(r+1,r);
		update(A[r+1],1);
		r++;
		debug("%d~%d cur = %d\n",l,r,cur);
		if(cur <= k)
			ans = max(ans,r-l+1);
		while(cur > k){
			debug("rem %d\n",l);
			update(A[l],-1);
			cur -= check(l,r);
			l++;
			debug("%d~%d cur = %d\n",l,r,cur);
		}

	}

	printf("%d\n",ans);

}