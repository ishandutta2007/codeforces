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

set<int>s [100100];

int v[100100];

main(){
		int ans=9999999;
		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%d",v+i),ans=min(ans,v[i]);

		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b),a--,b--;
			if(v[a] != v[b])
				s[v[a]].insert(v[b]), s[v[b]].insert(v[a]);}

		

		for(int i=1;i<=100000;i++)
			if(s[i].size() > s[ans].size())
				ans = i;

		printf("%d\n",ans);

}