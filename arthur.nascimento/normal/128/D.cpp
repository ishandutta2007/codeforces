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
#define maxn 100100

using namespace std;

int v[maxn];
int f[maxn];

main(){

		int n;
		scanf("%d",&n);

		int mi = 1000000000, ma = 0;
		for(int i=0;i<n;i++)
			scanf("%d",v+i), mi = min(mi,v[i]), ma = max(ma,v[i]);

		if(ma-mi > n){
			printf("NO\n");
			return 0;
		}

		for(int i=0;i<n;i++)
			debug("%d ",v[i]-mi);

		for(int i=0;i<n;i++)
			f[v[i]-mi]++;

		ma -= mi;

		int ans = 1;

		for(int i=1;i<ma;i++){
			if(f[i] < 2) ans = 0;
			f[i] -= 2;
		}

		f[0]--;
		f[ma]--;

		for(int i=0;i<ma;i++){
			if(f[i] > f[i+1]) ans = 0;
			f[i+1] -= f[i];
		}

		if(f[ma]) ans = 0;

		printf("%s\n",ans?"YES":"NO");

}