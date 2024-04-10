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
#define maxn 100100

using namespace std;

vector<pii> a;
vector<pii> b;

vector<int> L[maxn];
int v[maxn];

int dfs(int x,int p){

	int ret = v[x];

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++){
		int u = dfs(*it,x);
		printf("%d %d %d\n",x+1,*it+1,u);
		ret -= u;
	}

	return ret;

}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int c;
			scanf("%d%d",&c,v+i);
			if(c == 0)
				a.pb(pii(i,v[i]));
			else
				b.pb(pii(i,v[i]));
		}

		int pa=0, pb=0;
		int r = 0;

		for(int i=0;i<n-1;i++){

			debug("! %d %d\n",pa,pb);

			if((a[pa].second < b[pb].second) || (a[pa].second == b[pb].second && pb == b.size()-1)){
				L[b[pb].first].pb(a[pa].first);
				b[pb].second -= a[pa].second;
				r = b[pb].first;
				pa++;
			}
			else {
				L[a[pa].first].pb(b[pb].first);
				a[pa].second -= b[pb].second;
				r = a[pa].first;
				pb++;
			}

		}

		debug("ok");

		dfs(r,r);

}