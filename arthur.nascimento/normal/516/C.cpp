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

long long T[8*maxn];
long long dir[8*maxn];
long long esq[8*maxn];
long long sum[8*maxn];

long long d[2*maxn];
long long h[2*maxn];
int n;

void update(int init,int fim,int p,int pos){

	debug("upd %d %d\n",init,fim);

	if(init > pos || fim < pos) return;
	
	if(init == fim){
		T[p] = dir[p] = esq[p] = 2*h[pos];
		return;
	}

	int mid = (init+fim)/2;
	update(init,mid,2*p,pos);
	update(mid+1,fim,2*p+1,pos);

	T[p] = max(T[2*p], T[2*p+1]);
	T[p] = max(T[p], dir[2*p] + esq[2*p+1] + d[mid]);

	esq[p] = max(esq[2*p], sum[2*p] + d[mid] + esq[2*p+1]);
	dir[p] = max(dir[2*p+1], sum[2*p+1] + d[mid] + dir[2*p]);

	sum[p] = sum[2*p] + sum[2*p+1] + d[mid];

	debug("%d~%d T = %I64d\n",init,fim,T[p]);

}

long long ans;
long long dd;
long long ee;
long long s;
int first;

void query(int init,int fim,int p,int l,int r){

	if(init > r || fim < l) return;

	if(init >= l && fim <= r){
		assert(p >= 0 && p < 8*maxn);
		if(first){
			ans = T[p];
			dd = dir[p];
			ee = esq[p];
			s = sum[p];
			first = 0;
			return;
		}
		ans = max(ans,T[p]);
		assert(init != 0);
		ans = max(ans,dd+esq[p]+d[init-1]);
		ee = max(ee,s+d[init-1]+esq[p]);
		dd = max(dir[p],sum[p]+d[init-1]+dd);
		s += sum[p]+d[init-1];
		return;
	}

	int mid = (init+fim)/2;
	query(init,mid,2*p,l,r);
	query(mid+1,fim,2*p+1,l,r);

}

main(){

		int m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++) scanf("%I64d",d+i);

		for(int i=0;i<n;i++) scanf("%I64d",h+i);

		for(int i=n;i<2*n;i++){
			d[i] = d[i-n];
			h[i] = h[i-n];
			//update(0,2*n-1,1,i);
		}

		for(int i=0;i<2*n;i++)
			update(0,2*n-1,1,i);

		while(m--){
			int a,b;
			scanf("%d%d",&a,&b), a--, b--;
			int A = b+1, B = a-1;

			if(A > B) B += n;

			debug("A=%d B=%d\n",A,B);

			assert(B > A && A >= 0 && B < 2*n);

			ans = dd = ee = s = 0;
			first = 1;
			query(0,2*n-1,1,A,B);
			printf("%I64d\n",ans);

		}

}