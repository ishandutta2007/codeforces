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
#define mod 1000000007
#define maxn 5050

using namespace std;

map<int,int> mp;

int a[maxn];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",a+i);
			
		for(int i=0;i<n;i++){
			int sum = 0;
			for(int j=1;j<=k;j++){
				sum += a[i];
				if(mp[sum] == 0)
					mp[sum] = j;
				mp[sum] = min(mp[sum],j);
			}
		}


		int q;
		scanf("%d",&q);

		while(q--){
			int b;
			scanf("%d",&b);

			int ans = k+1;
			for(int i=0;i<n;i++)
				for(int j=1;j<=k;j++){
					int cur = j*a[i];
					if(b != cur && mp[b-cur] == 0) continue;
					ans = min(ans, j + mp[b-cur]);
				}
			if(ans <= k)
				printf("%d\n",ans);
			else
				printf("-1\n");
		}

}