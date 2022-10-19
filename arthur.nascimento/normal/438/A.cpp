#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back

using namespace std;

pii v[1010];
int foi[1010];
int val[1010];

vector<int> L[1010];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++){
			scanf("%d",&v[i].first);
			val[i] = v[i].first;
			v[i].second = i;
		}
		
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		sort(v,v+n);

		int ans = 0;

		for(int i=n-1;i>=0;i--){

			debug("%d %d\n",v[i].first,v[i].second);

			foi[v[i].second] = 1;
			for(vector<int> :: iterator it = L[v[i].second].begin(); it < L[v[i].second].end(); it++)
				if(!foi[*it])
					ans += val[*it];

		}

		printf("%d\n",ans);


}