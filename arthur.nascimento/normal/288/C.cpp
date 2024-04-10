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

int f[1001000];

main(){

		int n;
		scanf("%d",&n);

		set<int> S;

		for(int i=0;i<=n;i++)
			S.insert(i);

		while(S.size()){

			int k = *(--S.end());
			S.erase(k);

			if(k == 0 || S.size() == 0){
				f[k] = 0;
				f[0] = k;
				break;
				}

			int p = 1;
			while(2*p <= k)
				p*=2;

			int a = (~k) & (p-1);

			f[k] = a;
			f[a] = k;

			S.erase(a);
			}

		printf("%I64d\n",(long long) n *(n+1));
		for(int i=0;i<=n;i++)
			printf("%d ",f[i]);

}