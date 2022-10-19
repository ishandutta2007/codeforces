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
#define mod 1000000007

using namespace std;

int v[maxn];

main(){


		int n,k;
		scanf("%d%d",&n,&k);
		int ans = n-1;
		for(int i=0;i<k;i++){
			int m;
			scanf("%d",&m);
			for(int j=0;j<m;j++)
				scanf("%d",v+j);
			ans += m-1;
			if(v[0] != 1) continue;
			for(int i=1;i<m && v[i] == i+1;i++) ans -= 2;
		}

		cout << ans << endl;

}