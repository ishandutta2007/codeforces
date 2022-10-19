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

#define inf (999999999)
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

set<pii> usa;
vector<int> ans[3];
int foi[100100];

vector<int> L[100100];

void dfs(int x,int p){

	foi[x] = 1;

	vector<int> v;

	debug("dfs %d\n",x);


	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(!foi[*it]) 
			dfs(*it,x);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p && usa.find(pii(x,*it)) == usa.end()){
			v.pb(*it);debug("%d pb %d\n",x,*it);}

	if(v.size()%2) v.pb(p);

	debug("%d %d\n",x,v.size());

	for(int i=0;i<v.size();i+=2){
		ans[0].pb(v[i]);
		ans[1].pb(x);
		ans[2].pb(v[i+1]);
		usa.insert(pii(v[i],x));
		usa.insert(pii(x,v[i]));
		usa.insert(pii(v[i+1],x));
		usa.insert(pii(x,v[i+1]));
	}

}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		if(m%2 == 1){
			printf("No solution\n");
			return 0;
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		dfs(0,0);

		for(int i=0;i<m/2;i++)
			printf("%d %d %d\n",1+ans[0][i],1+ans[1][i],1+ans[2][i]);

}