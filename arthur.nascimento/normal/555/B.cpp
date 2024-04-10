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
#define maxn 200200
#define mod 1000000007

using namespace std;

struct itv {
	long long l,r;
	int idx;
	itv(long long l=0,long long r=0,int idx=0): l(l), r(r), idx(idx) {}
	bool operator<(itv comp) const {
		if(r == comp.r)
			return idx < comp.idx;
		return r < comp.r;
	}
};

itv v[maxn];

bool comp(itv a,itv b){
	return a.l < b.l;
}

long long L[maxn];
long long R[maxn];

pll r[maxn];

int ans[maxn];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			scanf("%I64d%I64d\n",L+i,R+i);

		for(int i=1;i<n;i++){
			long long A = L[i]-R[i-1];
			long long B = R[i]-L[i-1];
			v[i-1] = itv(A,B,i-1);
		}

		sort(v,v+n-1,comp);

		int p = 0;

		for(int i=0;i<m;i++)
			scanf("%I64d",&r[i].first), r[i].second = i;
		sort(r,r+m);

		set<itv> S;

		for(int i=0;i<m;i++){
			while(p < n-1 && v[p].l <= r[i].first){
				S.insert(v[p]);
				debug("add %I64d-%I64d\n",v[p].l,v[p].r);
				p++;
			}
			debug("ve %I64d\n",r[i].first);
			while(S.size()){
				itv u = *S.begin();
				S.erase(u);
				if(u.r < r[i].first) continue;
				ans[u.idx] = r[i].second+1;
				debug("-> %I64d %I64d\n",u.l,u.r);
				break;
			}
		}

		int ok = 1;
		for(int i=0;i<n-1;i++)
			if(ans[i] == 0) ok = 0;

		if(ok == 0){
			printf("No\n");
			return 0;
		}
		printf("Yes\n");

		for(int i=0;i<n-1;i++)
			printf("%d ",ans[i]);
		printf("\n");

}