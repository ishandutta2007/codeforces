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
#define max3(a,b,c) max(max(a,b),c)

using namespace std;

vector<pii> L[maxn];
int val[maxn];
int foi[maxn];

void dfs(int x){
	foi[x] = 1;
	for(vector<pii> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(!foi[it->first]){
		val[it->first] = val[x] ^ it->second;
		dfs(it->first);
	}
}
main(){

		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<k;i++){
			int x,y;
			char ch;
			scanf("%d%d %c",&x,&y,&ch), x--, y--;
			if(ch == 'o') ch = 1;
			else ch = 0;
			int a = x-y, b = x+y;
			if(a < 0) a = -a;
			if(b >= n) b = n-1-(b-(n-1));
			debug("%d-%d\n",a,b);
			L[a].pb(pii(b+2,ch));
			L[b+2].pb(pii(a,ch));
		}
		
		int c = 0;
		for(int i=0;i<n+2;i++) if(!foi[i]) {
			c++;
			dfs(i);
		}

		int ans = 1;
		c -= 2;
		while(c--) ans = (2*ans) % mod;

		for(int i=0;i<n+2;i++)
			for(vector<pii> :: iterator it = L[i].begin(); it < L[i].end(); it++)
				if( (val[i]^val[it->first]) != it->second)
					ans = 0;

		printf("%d\n",ans);

}