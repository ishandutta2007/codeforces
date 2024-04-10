#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

struct ev {
	int idx,tipo,t;
	ev(int idx=0,int tipo=0,int t=0) : idx(idx), tipo(tipo), t(t) {}
	bool operator<(ev comp)const {
		return t < comp.t;}
}

v[200200];

pii T[4*300300];
int lazy[4*300300];

int init[100100];
int pos[100100];
int end[100100];

void build(int init,int fim,int p){

	if(init == fim){
		T[p] = pii(0,init);
		return;}

	build(init,(init+fim)/2,2*p);
	build((init+fim)/2+1,fim,2*p+1);

	T[p] = max(T[2*p], T[2*p+1]);

}

void refresh(int init,int fim,int p){

	T[p].first += lazy[p];

	if(init != fim)
		lazy[2*p] += lazy[p],
		lazy[2*p+1] += lazy[p];

	lazy[p] = 0;
}

void update(int init,int fim,int p,int upx,int upy,int val) {

	refresh(init,fim,p);

	if(init > upy || fim < upx)
		return;

	if(init >= upx && fim <= upy){
		lazy[p] += val;
		refresh(init,fim,p);
		return;}

	update(init,(init+fim)/2,2*p,upx,upy,val);
	update((init+fim)/2+1,fim,2*p+1,upx,upy,val);

	T[p] = max(T[2*p], T[2*p+1]);
}

pii query(int init,int fim,int p,int qx,int qy) {

	refresh(init,fim,p);

	if(init > qy || fim < qx)
		return pii(-1,-1);

	if(init >= qx && fim <= qy)
		return T[p];

	pii ret = max(
		query(init,(init+fim)/2,2*p,qx,qy),
		query((init+fim)/2+1,fim,2*p+1,qx,qy));

	T[p] = ret;

	return ret;
}

main(){

		int n;
		scanf("%d",&n);

		int maxn = 0;

		for(int i=0;i<n;i++){


			scanf("%d%d%d",init+i,pos+i,end+i);

			maxn = max(maxn, end[i]);

			v[2*i] = ev(i,1,init[i]);
			v[2*i+1] = ev(i,-1,pos[i]+1);

			}

		sort(v,v+2*n);

		int p = 0;

		int ans = 0;
		int l,r;

		build(0,maxn,1);

		while(p < 2*n){


			int p0 = p;

			while(p < 2*n && v[p0].t == v[p].t){

					update(0,maxn,1,pos[v[p].idx], end[v[p].idx], v[p].tipo);

					debug("up %d %d\n",v[p].idx,v[p].tipo);
					
					p++;
					}

			
			pii k = query(0,maxn,1,v[p0].t,maxn);

			if(k.first > ans){
				ans = k.first;
				l = v[p0].t;
				r = k.second;
				}
			debug("%d (%d~%d)\n",k.first,v[p0].t,k.second);
				
		}

		printf("%d\n",ans);

		debug("l=%d r=%d\n",l,r);

		for(int i=0;i<n;i++)
			if(init[i] <= l && end[i] >= r && pos[i] >= l && pos[i] <= r)
				printf("%d ",i+1);

}