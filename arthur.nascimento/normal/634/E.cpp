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
#define debug(args...)// fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300

typedef long long ll;
using namespace std;

int w[maxn];
vector<int> L[maxn];

int dg[maxn];

int cur;
int foi[maxn];
int peso[maxn];
int rem[maxn];
int tira[maxn];

int dfs(int v,int p,int mid){
	foi[v] = 1;
	if(w[v] < mid || rem[v])
		return 0;
	int a = peso[v];
	int X=0, Y=0;
	for(int i=0;i<L[v].size();i++)
		if(L[v][i] != p){
			int r = dfs(L[v][i],v,mid);
			if(r > X){
				Y = X;
				X = r;
			}
			else if(r > Y)
				Y = r;
		}
	int s = X+Y;
	cur = max(cur,s+a);
	return a+X;
}

int ret;
char ch;
inline int read(){
	ret = 0;
	while((ch=getchar()) >= '0')
		ret = 10*ret+ch-'0';
	return ret;
}

main(){	

	int n,k;
	n = read();
	k = read();

	for(int i=0;i<n;i++)
		w[i] = read();

	for(int i=0;i<n-1;i++){
		int a,b;
		a = read()-1;
		b = read()-1;
		L[a].pb(b);
		L[b].pb(a);
	}

	int low = 0, up = 1000000;

	while(low != up){
	
		int mid = (low+up+1)/2;
		debug("mid = %d\n",mid);

		for(int i=0;i<n;i++)
			tira[i] = (w[i] >= mid) ? 1 : 0;

		for(int i=0;i<n;i++)
			peso[i] = 1;

		queue<int> Q;

		for(int i=0;i<n;i++)
			rem[i] = 0;

		for(int i=0;i<n;i++){
			dg[i] = L[i].size();
			debug("dg[%d] = %d\n",i,dg[i]);
		}

		for(int i=0;i<n;i++)
			if(dg[i] == 1 && tira[i]){
				Q.push(i);
				debug("push %d\n",i);
			}

		debug("dg[1] = %d\n",dg[1]);

		cur = 0;

		while(Q.size()){
			int u = Q.front();
			debug("u %d\n",u);
			Q.pop();
			cur = max(cur,peso[u]);
			rem[u] = 1;
			for(int i=0;i<L[u].size();i++){
				dg[L[u][i]]--;
				peso[L[u][i]] += peso[u];
				if(dg[L[u][i]] == 1 && tira[L[u][i]]){
					Q.push(L[u][i]);
					debug("%d -> %d\n",u,L[u][i]);
				}
			}
		}

		for(int i=0;i<n;i++)
			debug("peso[%d] = %d\n",i,peso[i]);

		for(int i=0;i<n;i++)
			foi[i] = 0;

		for(int i=0;i<n;i++)
			if(!foi[i])
				dfs(i,i,mid);

		debug("cur %d\n",cur);

		if(cur >= k)
			low = mid;
		else
			up = mid-1;

	}

	printf("%d\n",low);
}