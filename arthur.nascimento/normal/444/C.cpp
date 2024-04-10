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
#define debug(args...) //fprintf(stderr,args)
#endif

#define pb push_back
#define x second.first
#define y second.second

using namespace std;

struct node {
	int mini,maxi;
	long long beauty;
	node(int a=0,int b=0,long long c=0): mini(a), maxi(b), beauty(c) {}
	node merge(node k){
		k.mini = min(k.mini,mini);
		k.maxi = max(k.maxi,maxi);
		k.beauty += beauty;
		return k;
	}
};

node T[4*100100];

int tem[4*100100];
long long soma[4*100100];
int seta[4*100100];

inline void refresh(int init,int fim,int p){

	if(init != fim){
		soma[2*p] += soma[p];
		soma[2*p+1] += soma[p];
		if(tem[p]){
			seta[2*p] = seta[p];
			tem[2*p] = 1;
			seta[2*p+1] = seta[p];
			tem[2*p+1] = 1;
		}
	}

	if(tem[p])
		T[p].mini = T[p].maxi = seta[p];
	T[p].beauty += soma[p] * (fim-init+1);

	tem[p] = soma[p] = seta[p] = 0;
}

void build(int init,int fim,int p){

	int mid = (init+fim)/2;
	if(init != fim){
		build(init,mid,2*p);
		build(mid+1,fim,2*p+1);
		T[p].mini = min(T[2*p].mini, T[2*p+1].mini);
		T[p].maxi = max(T[2*p].maxi, T[2*p+1].maxi);
		T[p].beauty = T[2*p].beauty + T[2*p+1].beauty;
		return;
	}
	T[p].mini = T[p].maxi = init+1;
	T[p].beauty = 0;
	return;

}

void update(int init,int fim,int p,int l,int r,int val){

	refresh(init,fim,p);

	if(init > r || fim < l)
		return;

	if(init >= l && fim <= r){
		soma[p] += abs(T[p].mini - val);
		seta[p] = val;
		debug("seta %d~%d := %d\n",init,fim,val);
		tem[p] = 1;
		refresh(init,fim,p);
		return;
	}

	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,val);
	update(mid+1,fim,2*p+1,l,r,val);

	T[p].mini = min(T[2*p].mini, T[2*p+1].mini);
	T[p].maxi = max(T[2*p].maxi, T[2*p+1].maxi);
	T[p].beauty = T[2*p].beauty + T[2*p+1].beauty;

}

int next2;
int n;
node query(int,int,int,int,int);

int search(int init,int fim,int p,int f,int val){

	refresh(init,fim,p);
	
	debug("search %d~%d (%d) val = %d\n",init,fim,f,val);

	if(init == fim){
		if(T[p].mini == val){
			
			next2 = max(next2,init);
		}
		return T[p].mini == val;
	}

	int mid = (init+fim)/2;

	if(T[p].mini == T[p].maxi && T[p].mini == val){
		next2 = max(next2,fim);
		return 1;
	}

	if(f < init){

		int u = search(init,mid,2*p,f,val);
		if(u){
			
			return search(mid+1,fim,2*p+1,f,val);
			}
		return 0;

	}

	if(f <= mid){debug("c2\n");
		int u = search(init,mid,2*p,f,val);
		if(u){
			node tt = query(0,n-1,1,f,mid);
			assert(mid >= f);
			assert(tt.mini == tt.maxi);
			return search(mid+1,fim,2*p+1,f,val);
			}
		return 0;
	}

	debug("c3\n");
	if(f > mid)
		return search(mid+1,fim,2*p+1,f,val);
		assert(0);
	

}

node query(int init,int fim,int p,int l,int r){

	refresh(init,fim,p);

	if(init > r || fim < l)
		return node(inf,-inf,0);

	if(init >= l && fim <= r)
		return T[p];

	int mid = (init+fim)/2;

	node ret = query(init,mid,2*p,l,r).merge(query(mid+1,fim,2*p+1,l,r));
	T[p].mini = min(T[2*p].mini, T[2*p+1].mini);
	T[p].maxi = max(T[2*p].maxi, T[2*p+1].maxi);
	T[p].beauty = T[2*p].beauty + T[2*p+1].beauty;
	return ret;
}

main(){

		int m;
		scanf("%d%d",&n,&m);

		build(0,n-1,1);

		while(m--){

			int t;
			scanf("%d",&t);

			if(t == 2){

				int l,r;
				scanf("%d%d",&l,&r), l--, r--;

				printf("%I64d\n",query(0,n-1,1,l,r).beauty);

			}

			else {

				int l,r,u;
				scanf("%d%d%d",&l,&r,&u), l--, r--;

				int cur = l;

				while(cur <= r){

					int low = cur, up = r;
					/*while(low-up){
						int mid = (low+up+1)/2;
						node tt = query(0,n-1,1,cur,mid);
						if(tt.mini == tt.maxi)
							low = mid;
						else {
							up = mid-1;
							debug("ops! %d != %d\n",tt.mini,tt.maxi);
						}
					}*/

					int yy = query(0,n-1,1,cur,cur).mini;
					next2 = 0;
					search(0,n-1,1,cur,yy);
					low = next2;
					low = min(low,r);
					assert(low >= cur);
					node tt = query(0,n-1,1,cur,low);
					assert(tt.mini == tt.maxi);
					
					debug("%d~%d\n",cur,low);
					update(0,n-1,1,cur,low,u);
					cur = low+1;


				}

			}

		}

}