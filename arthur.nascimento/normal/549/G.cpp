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
#define maxn 500500
#define mod 1000000007

using namespace std;

main(){

		int n;
		scanf("%d",&n);

		vector<int> v;		
		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v.pb(i+u);
		}

		sort(v.begin(), v.end());

		vector<int> ans;

		for(int i=0;i<n;i++)
			ans.pb(v[i]-i);

		int ok = 1;
		for(int i=1;i<n;i++) if(ans[i] < ans[i-1]) ok = 0;

		if(ok == 0){
			printf(":(\n");
			return 0;
		}

		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		printf("\n");

}