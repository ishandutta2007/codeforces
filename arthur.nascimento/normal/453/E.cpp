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

int t0[maxn];
int maxt[maxn];
int dt[maxn];

long long ans[maxn];
int t[maxn];
int a[maxn];
int b[maxn];

pii T[4*maxn];
int tt[4*maxn];
int lazy[4*maxn];

void refresh(int init,int fim,int p){

	if(tt[p] == 0) return;

	tt[p] = 0;
	T[p].first = T[p].second = lazy[p];

	if(init != fim){
		tt[2*p] = tt[2*p+1] = 1;
		lazy[2*p] = lazy[2*p+1] = lazy[p];
	}

	lazy[p] = 0;

}

void update(int init,int fim,int p,int l,int r,int val){

	refresh(init,fim,p);

	if(init > r || fim < l) return;

	if(init >= l && fim <= r){
		lazy[p] = val;
		tt[p] = 1;
		refresh(init,fim,p);
		return;
	}

	int mid = (init+fim)/2;

	update(init,mid,2*p,l,r,val);
	update(mid+1,fim,2*p+1,l,r,val);

	T[p].first = min(T[2*p].first,T[2*p+1].first);
	T[p].second = max(T[2*p].second,T[2*p+1].second);

}

pii query(int init,int fim,int p,int l,int r){

	refresh(init,fim,p);

	if(init > r || fim < l) return pii(inf,0);

	if(init >= l && fim <= r) return T[p];

	int mid = (init+fim)/2;
	
	pii A = query(init,mid,2*p,l,r);
	pii B = query(mid+1,fim,2*p+1,l,r);

	T[p].first = min(T[2*p].first,T[2*p+1].first);
	T[p].second = max(T[2*p].second,T[2*p+1].second);

	return pii(min(A.first,B.first),max(A.second,B.second));

}

int aa;
int search(int init,int fim,int p,int pos,int val){

	refresh(init,fim,p);

	if(init == fim){
		if(T[p].first != val || T[p].second != val){
			 return 1;}
		aa = init;
		return 0;
	}

	int mid = (init+fim)/2;

	if(pos < init){

		refresh(init,mid,2*p);
		if(T[2*p].first == T[2*p].second && T[2*p].first == val){
			aa = mid;
			int ret = search(mid+1,fim,2*p+1,pos,val);
			if(ret == 0) aa = fim;
			return ret;
		}

		return search(init,mid,2*p,pos,val);

	}
			
	if(pos <= mid){
		int u = search(init,mid,2*p,pos,val);
		if(u == 0){	aa = mid;
			int ret = search(mid+1,fim,2*p+1,pos,val);
			if(ret == 0) aa = fim;
			return ret;
		}
		return 1;
	}

	return search(mid+1,fim,2*p+1,pos,val);
	
}

vector<int> tree[4*maxn];
vector<long long> sum_max[4*maxn];
vector<long long> sum_dt[4*maxn];
vector<long long> sum_t0[4*maxn];

void build(int init,int fim,int p){

	tree[p].clear();
	sum_max[p].clear();
	sum_dt[p].clear();
	sum_t0[p].clear();

	if(init == fim){

		int u;
		if(dt[init] == 0){ u = inf;}

		else {
			int falta = maxt[init] - t0[init];
			u = falta / dt[init];
			if(falta % dt[init]) u++;
		}

		tree[p].pb(u);
		debug("leaf t = %d\n",u);
		sum_max[p].pb(maxt[init]);
		sum_dt[p].pb(dt[init]);
		sum_t0[p].pb(t0[init]);

		return;

	}

	int mid = (init+fim)/2;
	
	build(init,mid,2*p);
	build(mid+1,fim,2*p+1);

	int pa = 0, pb = 0;
	int ta = mid-init+1, tb = fim-mid;
	int cur = 0;

	while(pa+pb <= fim-init){

		int pick;
		if(pa == ta) pick = 1;
		else if(pb == tb) pick = 0;
		else if(tree[2*p][pa] < tree[2*p+1][pb]) pick = 0;
		else pick = 1;

		if(pick == 0){
			tree[p].pb(tree[2*p][pa]);
			sum_max[p].pb(sum_max[2*p][pa]-(pa?sum_max[2*p][pa-1]:0));
			if(cur) sum_max[p][cur] += sum_max[p][cur-1];
			sum_dt[p].pb(sum_dt[2*p][pa]-(pa?sum_dt[2*p][pa-1]:0));
			if(cur) sum_dt[p][cur] += sum_dt[p][cur-1];
			sum_t0[p].pb(sum_t0[2*p][pa]-(pa?sum_t0[2*p][pa-1]:0));
			if(cur) sum_t0[p][cur] += sum_t0[p][cur-1];
			pa++;
		}
		else {
			tree[p].pb(tree[2*p+1][pb]);
			sum_max[p].pb(sum_max[2*p+1][pb]-(pb?sum_max[2*p+1][pb-1]:0));
			if(cur) sum_max[p][cur] += sum_max[p][cur-1];
			sum_dt[p].pb(sum_dt[2*p+1][pb]-(pb?sum_dt[2*p+1][pb-1]:0));
			if(cur) sum_dt[p][cur] += sum_dt[p][cur-1];
			sum_t0[p].pb(sum_t0[2*p+1][pb]-(pb?sum_t0[2*p+1][pb-1]:0));
			if(cur) sum_t0[p][cur] += sum_t0[p][cur-1];
			pb++;
		}
		
		cur++;
	}

}

long long query2(int init,int fim,int p,int l,int r,int tt){

	long long e = 0;

	for(int i=l;i<=r;i++)
		e += min((long long)maxt[i],(long long)t0[i] + (long long)tt * dt[i]);

	//return e;

	if(init > r || fim < l) return 0;

	if(init >= l && fim <= r){

		debug("hey!\n");

		int low = 0, up = tree[p].size()-1;
		int len = up;


		if(tree[p][up] <= tt){debug("!\n");
			return sum_max[p][up];}

		if(tree[p][0] > tt){debug("!!\n");
			return sum_t0[p][up] + tt * sum_dt[p][up];}

		while(up-low){
			int mid = (low+up+1)/2;
			if(tree[p][mid] <= tt)
				low = mid;
			else
				up = mid-1;
		}

		long long ret = sum_max[p][up] + (sum_t0[p][len] - sum_t0[p][up]) + (long long)tt * (sum_dt[p][len] - sum_dt[p][up]);
		debug("query2 %d~%d tt = %d returns %d\n",init,fim,tt,ret);
		debug("up = %d\n",up);
		return ret;
	}

	int mid = (init+fim)/2;

	return query2(init,mid,2*p,l,r,tt) + query2(mid+1,fim,2*p+1,l,r,tt);

}
	
main(){

		int n,q;
		scanf("%d",&n);

		vector<int> vv;

		for(int i=0;i<n;i++){
			scanf("%d%d%d",t0+i,maxt+i,dt+i);
			vv.pb(t0[i]);
			t0[i] = 0;
		}

		build(0,n-1,1);

		scanf("%d",&q);
		
		for(int i=0;i<q;i++)
			scanf("%d%d%d",t+i,a+i,b+i), a[i]--, b[i]--;

		update(0,n-1,1,0,n-1,q);

		for(int i=q-1;i>=0;i--){

			int u = a[i];

			while(u <= b[i]){

				int low = u, up = b[i];

				/*while(low-up){
					int mid = (up+low+1)/2;
					pii k = query(0,n-1,1,u,mid);
					if(k.first == k.second)
						low = mid;
					else
						up = mid-1;
				}*/

				aa = u;
				search(0,n-1,1,u,query(0,n-1,1,u,u).first);
				aa = min(aa,b[i]);
				up = aa;
				debug("aa = %d\n",aa);

				int y = query(0,n-1,1,u,up).first;

				if(y != q){
					debug("query %d writes to %d (%d~%d)\n",i,y,u,up);
					ans[y] += query2(0,n-1,1,u,up,t[y]-t[i]);
				}

				u = up + 1;

			}

			update(0,n-1,1,a[i],b[i],i);

		}

		for(int i=0;i<n;i++)
			t0[i] = vv[i];

		build(0,n-1,1);

		int u = 0;

		while(u < n){

			int low = u, up = n-1;

			/*while(low-up){
				int mid = (low+up+1)/2;
				pii k = query(0,n-1,1,u,mid);
				if(k.first == k.second)
					low = mid;
				else
					up = mid-1;
			}*/

			aa = u;
			search(0,n-1,1,u,query(0,n-1,1,u,u).first);
			up = aa;
			
			int y = query(0,n-1,1,u,up).first;

			if(y != q){
				debug("init writes to query %d (%d~%d)\n",y,u,up);
				ans[y] += query2(0,n-1,1,u,up,t[y]);
			}

			u = up + 1;

		}	

		for(int i=0;i<q;i++)
			printf("%I64d\n",ans[i]);	

}