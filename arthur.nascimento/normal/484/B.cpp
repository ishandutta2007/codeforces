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
#define maxn 100100

using namespace std;

int foi[1001000];
int v[1001000];

main(){

		int n;
		scanf("%d",&n);

		multiset<int> st;

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
		}

		sort(v,v+n);

		int ans = 0;

		for(int i=0;i<n;i++){
		
			//st.erase(st.find(v[i]));
			if(foi[v[i]]) continue;
			foi[v[i]] = 1;

			for(int j=1;v[i]*(j-1) <= 1000000; j++){

				int* a = lower_bound(v,v+n,v[i]*j);
				if(a == v) continue;
				int u  =  *(a-1);
				if(u >= v[i])
					ans = max(ans,u%v[i]);
				

			}

		}

		printf("%d\n",ans);

}