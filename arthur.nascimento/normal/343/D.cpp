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

int a[500500];
int b[500500];
int pre[500500];
int qnt = 0 ;

vector<int> L[500500];

void dfs(int x,int p){

	a[qnt] = b[qnt] = pre[x] = qnt++;
	debug("dfs %d\n",pre[x]);


	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			dfs(*it, x);
			a[pre[x]] = min(a[pre[x]], a[pre[*it]]);
			b[pre[x]] = max(b[pre[x]], b[pre[*it]]);
		}

	debug("%d: %d~%d\n",pre[x],a[x],b[x]);

}

int T[500500*4][2];
int lazy[500500*4];

int refresh(int init,int fim,int p){

	T[p][0] = max(T[p][0], lazy[p]);

	if(init != fim)
		lazy[2*p] = max(lazy[2*p], lazy[p]),
		lazy[2*p+1] = max(lazy[2*p+1], lazy[p]);

}

void update(int init,int fim,int p,int upx,int upy,int val){

	refresh(init,fim,p);

	if(fim < upx || init > upy)
		return;

	if(init >= upx && fim <= upy){
		lazy[p] = max(lazy[p], val);
		refresh(init,fim,p);
		return;
	}

	update(init,(init+fim)/2,2*p,upx,upy,val);
	update((init+fim)/2+1,fim,2*p+1,upx,upy,val);

}


void update2(int init,int fim,int p,int up,int val){

	if(fim < up || init > up)
		return;

	if(init >= up && fim <= up){
		T[p][1] = val;
		return;
	}

	update2(init,(init+fim)/2,2*p,up,val);
	update2((init+fim)/2+1,fim,2*p+1,up,val);

	T[p][1] = max(T[2*p][1], T[2*p+1][1]);

}

int query(int init,int fim,int p,int qx,int qy,int t){

	refresh(init,fim,p);

	if(fim < qx || init > qy)
		return 0;

	if(init >= qx && fim <= qy)
		return T[p][t];

	return max(
		query(init,(init+fim)/2,2*p,qx,qy,t),
		query((init+fim)/2+1,fim,2*p+1,qx,qy,t));

}


main(){

		int n;
		scanf("%d",&n);

		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			L[x].push_back(y);
			L[y].push_back(x);
		}

		int q;
		scanf("%d",&q);

		dfs(0,0);

		for(int i=1;i<=q;i++){
			
			int v,t;
			scanf("%d%d",&t,&v);

			v = pre[v-1];

			if(t == 1)
				update(0,n-1,1,a[v],b[v],i);

			if(t == 2)
				update2(0,n-1,1,v,i);

			if(t == 3){

				debug("v = %d a = %d b = %d\n",v,a[v],b[v]);

				int ench = query(0,n-1,1,v,v,0);
				int vaz = query(0,n-1,1,a[v],b[v],1);

				debug("ench = %d vaz = %d\n",ench,vaz);

				if(ench > vaz)
					printf("1\n");
				else
					printf("0\n");

				}

		}

}