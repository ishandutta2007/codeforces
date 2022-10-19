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
#define maxn 200200

using namespace std;

int ans[maxn];

vector<pii> rook;

struct query {
	int x1,x2,y1,y2,idx;
	bool operator<(query comp)const {
		return x1 > comp.x1;
	}
}

Q[maxn];

int T[4*maxn];
void clear(){
	memset(T,0,sizeof(T));
}
void update(int init,int fim,int p,int pos,int val){
	if(init > pos || fim < pos) return;
	if(init == fim){
		T[p] = val;
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,pos,val);
	update(mid+1,fim,2*p+1,pos,val);
	T[p] = max(T[2*p],T[2*p+1]);
}
int query(int init,int fim,int p,int l,int r){
	if(init > r || fim < l) return 0;
	if(init >= l && fim <= r) return T[p];
	int mid = (init+fim)/2;
	return max(query(init,mid,2*p,l,r), query(mid+1,fim,2*p+1,l,r));
}



void solve(int n,int m,int q){

	debug("oi..\n\n");
	int k = rook.size();

	sort(rook.begin(), rook.end());
	reverse(rook.begin(), rook.end());

	clear();
	for(int i=0;i<m;i++)
		update(0,m,1,i,n);

	sort(Q,Q+q);

	int ptr = 0;

	for(int i=0;i<q;i++){

		while(ptr < k && rook[ptr].first >= Q[i].x1){
			debug("bota torre (%d;%d)\n",rook[ptr].first,rook[ptr].second);
			update(0,m,1,rook[ptr].second,rook[ptr].first);
			ptr++;
		}

		int u = query(0,m,1,Q[i].y1,Q[i].y2);
		debug("query %d: u = %d\n",Q[i].idx,u);
		if(u <= Q[i].x2) ans[Q[i].idx]++;

	}

}
		

main(){

		int n,m,k,q;
		scanf("%d%d%d%d",&n,&m,&k,&q);

		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y), x--, y--;
			rook.pb(pii(x,y));
		}

		for(int i=0;i<q;i++){
			Q[i].idx = i;
			scanf("%d%d%d%d",&Q[i].x1,&Q[i].y1,&Q[i].x2,&Q[i].y2), Q[i].x1--, Q[i].x2--, Q[i].y1--, Q[i].y2--;
		}

		solve(n,m,q);

		for(int i=0;i<k;i++)
			swap(rook[i].first,rook[i].second);
		for(int i=0;i<q;i++){
			swap(Q[i].x1,Q[i].y1);
			swap(Q[i].x2,Q[i].y2);
		}

		solve(m,n,q);

		for(int i=0;i<q;i++)
			if(ans[i])
				printf("YES\n");
			else
				printf("NO\n");

}