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
#define maxn 30300
#define mod 1000000007

using namespace std;

set<pip> s[maxn];
set<int> good;

int len[maxn];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<4*n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c), a--,  b--, c--;
			s[a].insert(pip(i,pii(b,c)));
		}

		for(int i=0;i<n;i++)
			len[i] = 8;

		vector<int> ans;

		for(int i=0;i<n;i++)
			good.insert(i);

		while(good.size()){

			int u = *(good.begin());
			good.erase(u);

			debug("u %d\n",u);

			if(s[u].size() == 0) continue;

			pip k = *(s[u].begin());
			s[u].erase(k);

			ans.pb(k.first);
			debug("+ %d\n",k.first);
			len[u]++;
			len[k.second.first]--;
			len[k.second.second]--;
			good.insert(k.second.first);
			good.insert(k.second.second);
			if(len[u] < 9) good.insert(u);

		}

		reverse(ans.begin(),ans.end());

		printf("YES\n");
		for(int i=0;i<4*n;i++)
			printf("%d ",1+ans[i]);


}