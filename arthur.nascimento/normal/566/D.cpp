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
#define maxn 200200
#define mod 1000000007

using namespace std;

int pai[maxn];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		set<int> S;
		for(int i=0;i<n;i++) S.insert(i);

		for(int i=0;i<n;i++) pai[i] = i;

		while(q--){

			int t,a,b;
			scanf("%d%d%d",&t,&a,&b), a--, b--;

			if(t == 1){
				pai[find(a)] = find(b);
				continue;
			}
			if(t == 3){
				if(find(a) == find(b))
					printf("YES\n");
				else
					printf("NO\n");
				continue;
			}

			pai[find(b)] = find(a);
			debug("merge %d %d\n",a,b);

			for(set<int> :: iterator it = S.lower_bound(a);it != S.end() && *it <= b; it++){

				int A = find(a);
				int B = find(*it);
				debug("merge %d %d\n",a,*it);
				pai[A] = B;

				set<int> :: iterator it2 = it;

				if(it != S.begin()){
					it2--;
					if(find(*it2) == find(*it)){ debug("del %d\n",*it2); S.erase(*it2);}
				}

				it2 = it;
				it2++;
				
				if(it2 != S.end())
					if(find(*it2) == find(*it)){debug("del %d\n",*it2); S.erase(*it2);}

			}

		}

}