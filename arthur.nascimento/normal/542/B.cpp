#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

struct ev {
	int t, tipo, end;
	ev(int t=0,int tipo=0,int end=0): t(t), tipo(tipo), end(end) {}
	bool operator<(ev comp)const{
		if(t != comp.t)
			return t > comp.t;
		return tipo < comp.tipo;
	}
};

int T[4*maxn];
int lazy[4*maxn];

void refresh(int init,int fim,int p){
	if(init != fim){
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
	}
	T[p] += lazy[p];
	lazy[p] = 0;
}

void update(int init,int fim,int p,int l,int r,int val){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return;
	if(init >= l && fim <= r){
		lazy[p] += val;
		refresh(init,fim,p);
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,val);
	update(mid+1,fim,2*p+1,l,r,val);
	T[p] = max(T[2*p],T[2*p+1]);
}

int query(int init,int fim,int p,int l,int r){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return -1;
	if(init >= l && fim <= r)
		return T[p];
	int mid = (init+fim)/2;
	int ret = max(query(init,mid,2*p,l,r),query(mid+1,fim,2*p+1,l,r));
	T[p] = max(T[2*p],T[2*p+1]);
	return ret;
}

main(){

	int n,jmp;
	scanf("%d%d",&n,&jmp);

	multiset<ev> S;

	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(b < 0)
			continue;
		if(a < 0)
			a = 0;
		S.insert(ev(b,0));
		S.insert(ev(b,1));
		S.insert(ev(a,2,b));
	}

	int qnt = 0;
	int best = 0;
	int sz = 0;

	vector<int> v;

	while(S.size()){

		ev e = *S.begin();
		S.erase(S.begin());

		if(e.tipo == 0){
			debug("add t = %d\n",e.t);
			qnt++;
		}

		if(e.tipo == 1){

			int u = qnt, t = e.t;

			int low = 0, up = sz-1;
			if(sz && -v[0] >= t + jmp){
				int r = upper_bound(v.begin(), v.end(), -t-jmp) - v.begin() - 1;
				int q = query(0,n-1,1,0,r);
				debug("qry %d~%d -> %d\n",0,r,q);
				u += q;
			}

			debug("ask t = %d -> %d\n",e.t,u);

			if(u > best){
				best = u;
				debug("upd %d := %d\n",sz,best-qnt);
				update(0,n-1,1,sz,sz,best-qnt);
				v.pb(-t);
				sz++;
				S.insert(ev(t-jmp,1));
			}

		}

		if(e.tipo == 2){

			debug("rem t = %d\n",e.t);
			if(sz && -v[sz-1] <= e.end){
				int r = lower_bound(v.begin(), v.end(), -e.end) - v.begin();
				debug("upd %d~%d ++\n",r,sz-1);
				update(0,n-1,1,r,sz-1,1);
			}	
			qnt--;
			
		}

	}

	printf("%d\n",best);

}