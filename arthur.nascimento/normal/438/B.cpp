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

int pai[100100];
long long len[100100];
int vv[100100];

int foi[100100];

vector<int> L[100100];

pii v[100100];

int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);}

void merge(int a,int b){

	a = find(a);
	b = find(b);

	if(a == b)
		return;

	pai[a] = b;
	len[b] += len[a];

}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++){
			scanf("%d",&v[i].first);
			vv[i] = v[i].first;
			v[i].second = i;
		}

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--,b--;
			L[a].pb(b);
			L[b].pb(a);
		}

		sort(v,v+n);

		for(int i=0;i<n;i++)
			pai[i] = i, len[i] = 1;

		long long ans = 0;

		for(int i=n-1;i>=0;i--){

			int u = v[i].second;
			long long peso = v[i].first;

			foi[u] = 1;

			debug("u=%d\n",u);

			for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++){
				if(!foi[*it])
					continue;
				int A = find(*it);
				int B = find(u);
				if(A == B)
					continue;
				//peso = min(v[u].first, vv[*it]);
				ans += peso * len[A] * len[B];
				merge(A,B);
				debug("merge %d %d\n",u,*it);
				debug("ans = %I64d\n",ans);
			}

			

		}

		long long n2 = (long long)n*n-n;
		printf("%lf\n",(double)(2*ans)/(n2));

}