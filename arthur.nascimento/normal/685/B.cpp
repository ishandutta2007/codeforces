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

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 500500
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

vector<int> L[maxn];
int ans[maxn];

int cont = 0;
int size[maxn];
set<pii> S[maxn];

int dfs(int v){

	int f = L[v].size();

	if(f == 0){
		ans[v] = v;
		S[cont].insert(pii(1,v));
		size[v] = 1;
		cont++;
		return cont-1;
	}

	int large;
	int t = -1;
	size[v] = 1;

	vector<int> e;

	for(int i=0;i<L[v].size();i++){
		int u = dfs(L[v][i]);
		size[v] += size[L[v][i]];
		debug("comp %d\n",(int)S[u].size());
		if((int)S[u].size() > t){
			t = (int)S[u].size();
			large = u;
		}
		e.pb(u);
	}

//	debug("go %d large %d\n",v,large);

	for(int i=0;i<e.size();i++){
		int u = e[i];
		if(u == large)
			continue;
		for(set<pii> :: iterator it = S[u].begin(); it != S[u].end(); it++){
	//		debug("ins %d %d\n",it->first,it->second);
			S[large].insert(*it);
		}
	}

	int a = 1+size[v]/2;

	S[large].insert(pii(size[v],v));

	

	ans[v] = S[large].lower_bound(pii(a,-1)) -> second;
	//debug("ans %d\n",ans[v]);

	return large;
}
	

main(){

	int n,q;
	scanf("%d%d",&n,&q);

	for(int i=1;i<n;i++){
		int p;
		scanf("%d",&p), p--;
		L[p].pb(i);
	}

	dfs(0);

	for(int i=0;i<q;i++){
		int a;
		scanf("%d",&a), a--;
		printf("%d\n",ans[a]+1);
	}

}