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
#define maxn 1001000

using namespace std;

struct lista {

	map<int,int> pos;
	vector<pii> v;
	int n;

	lista(): n(0) {}

	int erase(){
		int ret = v[n-1].first;
		if(--v[n-1].second	== 0) n--;
		return ret;
	}	

	void merge(lista l){

		while(l.n) insert(l.erase());

	}

	int insert(int x){

		if(pos.find(x) == pos.end()){
			pos[x] = n;
			v.pb(pii(x,1));
			return n++;
		}

		int p = pos[x];
		int low=0,up=p-1;
		while(low != up && up >= 0){
			int mid = (low+up)/2;
			if(v[mid].second == v[p].second)
				up = mid;
			else
				low = mid+1;
		}
		if(p && v[p-1].second != v[p].second) low = p;

		swap(v[low].first,v[p].first);
		swap(pos[v[low].first],pos[v[p].first]);
		v[low].second++;

	}

	int query(int k){

		if(n == 0) return 0;

		if(v[0].second < k) return 0;

		int low = 0,up = n-1;

		while(low != up){
			int mid = (low+up+1)/2;
			if(v[mid].second >= k)
				low = mid;
			else
				up = mid-1;
		}

		return 1 + low;

	}

	void print(){

		debug("n = %d\n",n);
		for(int i=0;i<n;i++)
			debug("f[%d] = %d\n",v[i].first,v[i].second);
		debug("\n");

	}
	
}

v[maxn];
vector<int> L[maxn];
vector<pii> Q[maxn];
int ans[maxn];
int c[maxn];
int qnt = 0;

int dfs(int x,int p){

	if(x != 0 && L[x].size() == 1){
		v[qnt].insert(c[x]);
		for(vector<pii> :: iterator it = Q[x].begin(); it < Q[x].end(); it++)
		ans[it->second] = (it->first <= 1) ? 1 : 0;
		return qnt++;
	}

	vector<pii> u;

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(*it != p){

		int y = dfs(*it,x);
		u.pb(pii(v[y].n,y));

	}

	sort(u.begin(),u.end());
	reverse(u.begin(),u.end());

	for(int i=1;i<u.size();i++)
		v[u[0].second].merge(v[u[i].second]);

	v[u[0].second].insert(c[x]);

	if(x == 0)
		v[u[0].second].print();

	for(vector<pii> :: iterator it = Q[x].begin(); it < Q[x].end(); it++)
		ans[it->second] = v[u[0].second].query(it->first);

	return u[0].second;

}
	
main(){

		int n,q;
		scanf("%d%d",&n,&q);

		for(int i=0;i<n;i++)
			scanf("%d",c+i);

		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b),a--, b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		for(int i=0;i<q;i++){

			int t,k;
			scanf("%d%d",&t,&k), t--;
			Q[t].pb(pii(k,i));

		}

		dfs(0,0);

		for(int i=0;i<q;i++)
			printf("%d\n",ans[i]);

}