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

int Tmin[400400];
int Tqnt[400400];
int lazy[400400];

void create(int init,int fim,int p){

	Tqnt[p] = fim-init+1;
	int mid = (init+fim)/2;
	if(init != fim)
		create(init,mid,2*p),
		create(mid+1,fim,2*p+1);
}

void refresh(int init,int fim,int p){

	Tmin[p] += lazy[p];
	if(init != fim)
		lazy[2*p] += lazy[p],
		lazy[2*p+1] += lazy[p];
	lazy[p] = 0;

}

void calc(int p){

	if(Tmin[2*p] == Tmin[2*p+1])
		Tmin[p] = Tmin[2*p],
		Tqnt[p] = Tqnt[2*p] + Tqnt[2*p+1];

	if(Tmin[2*p] < Tmin[2*p+1])
		Tmin[p] = Tmin[2*p],
		Tqnt[p] = Tqnt[2*p];

	if(Tmin[2*p] > Tmin[2*p+1])
		Tmin[p] = Tmin[2*p+1],
		Tqnt[p] = Tqnt[2*p+1];

}

int query(int init,int fim,int p,int qx,int qy){

	refresh(init,fim,p);

	if(init > qy || fim < qx)
		return 0;

	if(init >= qx && fim <= qy)
		return Tmin[p] ? (fim-init+1) : (fim-init+1-Tqnt[p]);

	int mid = (init+fim)/2;
	int ret = query(init,mid,2*p,qx,qy) + query(mid+1,fim,2*p+1,qx,qy);

	calc(p);
	return ret;
}

void update(int init,int fim,int p,int upx,int upy,int val){

	refresh(init,fim,p);

	if(init > upy || fim < upx)
		return;

	if(init >= upx && fim <= upy){
		lazy[p] += val;
		refresh(init,fim,p);
		return;
	}

	int mid = (init+fim)/2;

	update(init,mid,2*p,upx,upy,val);
	update(mid+1,fim,2*p+1,upx,upy,val);

	calc(p);

}

vector<int> L[100100];
vector<int> upd[100100];

int n,m;
int a[100100];
int b[100100];
int pre[100100];
int ans[100100];
int cont = 0;

void dfs(int x,int p){

	pre[x] = cont++;
	a[x] = pre[x];
	b[x] = pre[x];

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			dfs(*it,x);
			a[x] = min(a[x], a[*it]);
			b[x] = max(b[x], b[*it]);
		}

	debug("%d~%d\n",a[x],b[x]);

}

void dfs2(int x,int p){

	for(vector<int> :: iterator it = upd[x].begin(); it < upd[x].end(); it++){
		update(0,n-1,1,a[x],b[x],1);
		update(0,n-1,1,a[*it],b[*it],1);
		debug("up %d~%d\n",a[x],b[x]);
		debug("up %d~%d\n",a[*it],b[*it]);
	}

	ans[x] = query(0,n-1,1,0,n-1);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p)
			dfs2(*it,x);

	for(vector<int> :: iterator it = upd[x].begin(); it < upd[x].end(); it++){
		update(0,n-1,1,a[x],b[x],-1);
		update(0,n-1,1,a[*it],b[*it],-1);
	}	

}

main(){

		scanf("%d%d",&n,&m);

		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			L[x].push_back(y);
			L[y].push_back(x);
		}

		create(0,n-1,1);
		dfs(0,0);

		for(int i=0;i<m;i++){
		
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;

			upd[x].push_back(y);
			upd[y].push_back(x);

		}

		dfs2(0,0);

		for(int i=0;i<n;i++)
			printf("%d ",max(ans[i]-1,0));

		printf("\n");

}