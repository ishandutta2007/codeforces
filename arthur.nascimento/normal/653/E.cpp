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
#define maxn 2002000
#define mod 1000000007

typedef long long ll;
using namespace std;

set<pii> bad;

set<int> S;

set<int> cur;

vector<int> L[maxn];

int foi[maxn];
int n;

void dfs(int v){
	debug("dfs %d\n",v);
	cur.insert(v);
	foi[v] = 1;
	int last = -1;
	vector<int> novos;
	for(vector<int> :: iterator it = L[v].begin(); it != L[v].end(); it++){
		int u = *it;
		for(set<int> :: iterator it2 = S.upper_bound(last); *it2 < u && it2 != S.end(); it2++)
			novos.pb(*it2);
		last = u;
	}
	{
		int u = n;
		for(set<int> :: iterator it2 = S.upper_bound(last); *it2 < u && it2 != S.end(); it2++)
			novos.pb(*it2);
		last = u;
	}
	for(int i=0;i<novos.size();i++)
		S.erase(novos[i]);
	for(int i=0;i<novos.size();i++)
		dfs(novos[i]);
	novos.clear();
}

main(){

	int m,k;
	scanf("%d%d%d",&n,&m,&k);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
		bad.insert(pii(a,b));
		bad.insert(pii(b,a));
	}

	for(int i=0;i<n;i++){
		S.insert(i);
		sort(L[i].begin(),L[i].end());
	}
	S.erase(0);

	int comps = 0;
	int ok = 1;
	
	for(int i=1;i<n;i++)
		if(!foi[i]){
			cur.clear();
			S.erase(i);
			dfs(i);
			int has = 0;
			debug("+ ");
			for(set<int> :: iterator it = cur.begin(); it != cur.end(); it++){
				debug("%d ",*it);
				if(bad.find(pii(0,*it)) == bad.end())
					has = 1;
			}
			debug("has %d\n",has);
			if(!has)
				ok = 0;
			comps++;
		}


	if(comps > k || ok == 0 || n-L[0].size()-1 < k)
		printf("impossible\n");
	else
		printf("possible\n");

}