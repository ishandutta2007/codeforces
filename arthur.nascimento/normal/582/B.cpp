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

#define inf 99999999999.
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

int best[303];
vector<int> lis(vector<int> v){
	memset(best,0,sizeof(best));
	int n = v.size();
	debug("lis %d\n",n);
	for(int i=0;i<n;i++){
		int a = 1;
		if(v[i] > 0)
			for(int j=0;j<=abs(v[i]);j++)
				a = max(a,1+best[j]);
		if(v[i] < 0)
			for(int j=abs(v[i]);j<=300;j++)
				a = max(a,1+best[j]);
		best[abs(v[i])] = a;
		debug("dp %d = %d\n",v[i],a);
	}
	vector<int> ret;
	ret.pb(0);
	for(int i=1;i<=300;i++)
		ret.pb(best[i]);
	return ret;
}
	
int f[303];

main(){

		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> v;

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u), f[u]++;
			v.pb(u);
		}
		if(k <= 3*n){
			vector<int> u;
			for(int i=0;i<k;i++)
				for(int j=0;j<n;j++)
					u.pb(v[j]);
			vector<int> ans = lis(u);
			int r = 0;
			for(int i=1;i<=300;i++)
				r = max(r,ans[i]);
			printf("%d\n",r);
			return 0;
		}

		for(int i=0;i<n-1;i++)
			for(int j=0;j<n;j++)
				v.pb(v[j]);

		vector<int> A = lis(v);
		reverse(v.begin(), v.end());
		for(int i=0;i<v.size();i++)
			v[i] = -v[i];
		vector<int> B = lis(v);
		int s = 0;
		for(int i=1;i<=300;i++){
			int aa=0, bb=0;
			for(int j=1;j<=i;j++) aa = max(aa,A[j]);
			for(int j=i;j<=300;j++) bb = max(bb,B[j]);
			if(f[i]) s = max(s,aa+bb+f[i]*(k-2*n));

		}
		printf("%d\n",s);

}