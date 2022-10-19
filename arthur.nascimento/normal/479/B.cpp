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
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

struct tower {
	int idx,h;
	tower(int idx=0,int h=0): idx(idx), h(h) {}
	bool operator<(tower comp)const{
		return h < comp.h;
	}
};

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		vector<tower> v;
		vector<pii> ans;

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v.pb(tower(i,u));
		}

		for(int i=0;i<k;i++){

			sort(v.begin(),v.end());
			if(v[0].h == v[n-1].h) break;
			ans.pb(pii(v[n-1].idx,v[0].idx));
			v[n-1].h--;
			v[0].h++;

		}

		sort(v.begin(),v.end());
		printf("%d %d\n",v[n-1].h-v[0].h,ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first+1,ans[i].second+1);

}