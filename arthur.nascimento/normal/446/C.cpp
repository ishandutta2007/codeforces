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

#define inf (1LL<<60)
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
#define mod 1000000009LL
#define maxn 300300

#define X second.first
#define Y second.second

using namespace std;

long long psum[maxn];

long long getsum(int a,int b){
	long long ret = psum[b];
	if(a) ret -= psum[a-1];
	return ret;
}

long long T[4*maxn];
pll lazy[4*maxn];

long long fib[maxn];

long long kth(long long a,long long b,int k){
	if(k == 1) return a;
	if(k == 2) return b;
	debug("kth %I64d %I64d %d\n",a,b,k);
	return (a * fib[k-2] + b * fib[k-1]) % mod;
}

int sum(int a,long long b,int k){
	return (kth(a,b,k+2)-b+10*mod) % mod;
}


void refresh(int init,int fim,int p){

	if(lazy[p].first == 0 && lazy[p].second == 0) return;

	int a = lazy[p].first;
	int b = lazy[p].second;

	lazy[p] = pll(0,0);
	int t = (init+fim)/2 - init + 1;

	T[p] = (T[p] + sum(a,b,fim-init+1)) % mod;
	if(init == 0 && fim == 3)debug(":= %I64d %d %d\n",T[p],a,b);

	if(init != fim){
		lazy[2*p].first += a;
		lazy[2*p].second += b;
		lazy[2*p+1].first += kth(a,b,t+1);
		lazy[2*p+1].second += kth(a,b,t+2);
		lazy[2*p].first %= mod;
		lazy[2*p].second %= mod;
		lazy[2*p+1].first %= mod;
		lazy[2*p+1].second %= mod;
	}

}

void update(int init,int fim,int p,int l,int r,int a,int b){

	refresh(init,fim,p);

	if(init > r || fim < l) return;

	if(init >= l && fim <= r){
		int u = kth(a,b,init-l+1);
		int v = kth(a,b,init-l+2);
		lazy[p].first += u;
		lazy[p].second += v;
		refresh(init,fim,p);
		return;
	}

	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,a,b);
	update(mid+1,fim,2*p+1,l,r,a,b);

	T[p] = (T[2*p] + T[2*p+1]) % mod;

}

long long query(int init,int fim,int p,int l,int r){

	refresh(init,fim,p);

	if(init > r || fim < l) return 0;

	if(init >= l && fim <= r) return T[p];

	int mid = (init+fim)/2;

	long long ret = (query(init,mid,2*p,l,r) + query(mid+1,fim,2*p+1,l,r)) % mod;
	T[p] = T[2*p] + T[2*p+1];
	return ret;

}

main(){

		fib[1] = fib[2] = 1;
		for(int i=3;i<maxn;i++)
			fib[i] = (fib[i-1]+fib[i-2]) % mod;

		int n,m;
		scanf("%d%d",&n,&m);

		long long sum = 0;
		for(int i=0;i<n;i++){
			int k;
			scanf("%d",&k);
			sum += k;
			psum[i] = sum;
		}

		while(m--){

			int t,l,r;
			scanf("%d%d%d",&t,&l,&r), l--, r--;

			if(t == 1)
				update(0,n-1,1,l,r,1,1);
			else
				printf("%d\n",(getsum(l,r)+query(0,n-1,1,l,r))%mod);

		}

}