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
#define maxn 200200

typedef long long ll;
using namespace std;

vector<int> L[maxn];
vector<int> peso[maxn];

int w[maxn];

double ans;
int where = -1;

int block[maxn];

int size[maxn];

void dfs(int v,int p){
	size[v] = 1;
	for(int i=0;i<L[v].size();i++)
		if(L[v][i] != p && !block[L[v][i]]){
			dfs(L[v][i],v);
			size[v] += size[L[v][i]];
		}
}

double dfs2(int v,int p,int d){
	
	double ret = sqrt(d) * w[v];
	
	for(int i=0;i<L[v].size();i++)
		if(L[v][i] != p)
			ret += dfs2(L[v][i],v,d+peso[v][i]);
			
	return ret;
	
}

double dfs3(int v,int p,int d){
	
	double ret = sqrt(d) * d * w[v];
	
	for(int i=0;i<L[v].size();i++)
		if(L[v][i] != p)
			ret += dfs3(L[v][i],v,d+peso[v][i]);
	
	return ret;
			
}			

void go(int v){

	dfs(v,v);
	int tot = size[v];
	int pai = v;
	
	
	while(1){
		int ok = 1;
		for(int i=0;i<L[v].size();i++)
			if(!block[L[v][i]] && L[v][i] != pai && size[L[v][i]] >= (tot+1)/2){
				ok = 0;
				pai = v;
				v = L[v][i];
				break;
			}
		if(ok)
			break;
	}
	
	double big = 0, child = -1;
	
	for(int i=0;i<L[v].size();i++)
		if(!block[L[v][i]]){
			double u = dfs2(L[v][i],v,peso[v][i]);
			if(u > big || child == -1){
				big = u;
				child = i;
			}
		}
	
	double eval = dfs3(v,v,0);
	
	if(where == -1 || eval < ans){
		ans = eval;
		where = v;
	}
	
	if(child != -1){
		block[v] = 1;
		go(L[v][child]);
	}
	
}

main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",w+i);
		
	for(int i=0;i<n-1;i++){
		int a,b,p;
		scanf("%d%d%d",&a,&b,&p), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
		peso[a].pb(p);
		peso[b].pb(p);
	}
	
	go(0);
	
	printf("%d %.10lf\n",where+1,ans);
	
}