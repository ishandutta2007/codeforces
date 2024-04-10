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
 
using namespace std;


set<int> S;
int ans[300300];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=1;i<=n;i++)
			S.insert(i);

		for(int i=0;i<m;i++){

			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);

			for(set<int> :: iterator it = S.lower_bound(a); *it <= b && it != S.end();){
				if(*it != x){
					ans[*it] = x;
					set<int> :: iterator it2 = it;
					it++;
					S.erase(it2);
					}
				else it++;
				}
			
			}

		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);

		}