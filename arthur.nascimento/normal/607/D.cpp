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

using namespace std;

long long T[4*maxn];
long long lazy[4*maxn];

void refresh(int init,int fim,int p){
	T[p] = (T[p]*lazy[p])%mod;
	if(init != fim){
		lazy[2*p] = (lazy[2*p]*lazy[p])%mod;
		lazy[2*p+1] = (lazy[2*p+1]*lazy[p])%mod;
	}
	lazy[p] = 1;
}

void update(int init,int fim,int p,int l,int r,int val){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return;
	if(init >= l && fim <= r){
		lazy[p] = (lazy[p]*val)%mod;
		refresh(init,fim,p);
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,val);
	update(mid+1,fim,2*p+1,l,r,val);
	T[p] = (T[2*p]+T[2*p+1])%mod;
}

void set(int init,int fim,int p,int pos,int val){
	refresh(init,fim,p);
	if(init > pos || fim < pos)
		return;
	if(init == fim){
		T[p] = val;
		return;
	}
	int mid = (init+fim)/2;
	set(init,mid,2*p,pos,val);
	set(mid+1,fim,2*p+1,pos,val);
	T[p] = (T[2*p]+T[2*p+1])%mod;
}

int query(int init,int fim,int p,int l,int r){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return 0;
	if(init >= l && fim <= r)
		return T[p];
	int mid = (init+fim)/2;
	int ret = query(init,mid,2*p,l,r) + query(mid+1,fim,2*p+1,l,r);
	T[p] = (T[2*p]+T[2*p+1])%mod;
	return ret%mod;
}

long long exp(long long a,long long b){
	if(b == 0)
		return 1;
	long long ret = exp(a,b/2);
	ret = (ret*ret)%mod;
	if(b%2)
		ret = (a*ret)%mod;
	return ret;
}

int inv(long long a){
	return exp(a,mod-2);
}

vector<int> L[maxn];
int A[maxn];
int B[maxn];
long long dg[maxn];
int v[maxn];
int cnt;

int dfs(int v){
	A[v] = B[v] = cnt;
	cnt++;
	for(int i=0;i<L[v].size();i++)
		B[v] = dfs(L[v][i]);
	return B[v];
}

int qt[maxn];
int qv[maxn];
int pai[maxn];

main(){

	int n=1, q;
	scanf("%d%d",v,&q);
	
	for(int i=0;i<q;i++){
		int t,a;
		scanf("%d%d",&t,&a), a--;
		qt[i] = t;
		if(t == 1){
			scanf("%d",v+n);
			qv[i] = n;
			pai[n] = a;
			L[a].pb(n);
			n++;
		}
		else
			qv[i] = a;
	}

	dfs(0);

	for(int i=0;i<4*n;i++)
		lazy[i] = 1;

	set(0,n-1,1,A[0],v[0]);

	for(int i=0;i<q;i++){

		if(qt[i] == 2){
		
			int a = qv[i];
			long long u = query(0,n-1,1,A[a],B[a]);
			if(a){
				long long m = query(0,n-1,1,A[pai[a]],A[pai[a]]);
				m = (m*inv(v[pai[a]]))%mod;
				u = (u*inv(m))%mod;
			}
			printf("%I64d\n",u);
		}

		if(qt[i] == 1){

			int a = qv[i];
			int p = pai[a];
			long long m = query(0,n-1,1,A[p],A[p]);
			m = (m*inv(v[p]))%mod;
			set(0,n-1,1,A[a],(m*v[a])%mod);
			dg[p]++;
			long long r = ((dg[p]+1)*inv(dg[p]))%mod;
			update(0,n-1,1,A[p],B[p],r);

		}

	}

}