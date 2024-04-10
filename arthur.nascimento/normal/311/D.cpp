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
#define mod 95542721
#define maxn 100100
using namespace std;
typedef long long ll;

int T[50][4*maxn];
int lazy[4*maxn];
int v[maxn];

void build(int init,int fim,int p){

	if(init == fim){
		T[0][p] = v[init]%mod;
		for(int i=1;i<48;i++){
			T[i][p] = ((long long) T[i-1][p] * T[i-1][p]) % mod;
			T[i][p] = ((long long) T[i][p] * T[i-1][p]) % mod;
		}
		return;
	}

	int mid = (init+fim)/2;
	build(init,mid,2*p);
	build(mid+1,fim,2*p+1);

	for(int i=0;i<48;i++)
		T[i][p] = (T[i][2*p] + T[i][2*p+1]) % mod;

}

int aux[50];

void refresh(int init,int fim,int p){

	if(lazy[p] == 0)
		return;
	lazy[p] %= 48;
	if(init != fim){
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
	}
	for(int i=0;i<48;i++)
		aux[i] = T[(i+lazy[p])%48][p];
	for(int i=0;i<48;i++)
		T[i][p] = aux[i];
	lazy[p] = 0;

}

void update(int init,int fim,int p,int l,int r){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return;
	if(init >= l && fim <= r){
		lazy[p]++;
		refresh(init,fim,p);
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r);
	update(mid+1,fim,2*p+1,l,r);
	for(int i=0;i<48;i++)
		T[i][p] = (T[i][2*p] + T[i][2*p+1]) % mod;
}

int query(int init,int fim,int p,int l,int r){
	refresh(init,fim,p);
	if(init > r || fim < l)
		return 0;
	if(init >= l && fim <= r)
		return T[0][p];
	int mid = (init+fim)/2;
	int ret = query(init,mid,2*p,l,r) + query(mid+1,fim,2*p+1,l,r);
	for(int i=0;i<48;i++)
		T[i][p] = (T[i][2*p]+T[i][2*p+1])%mod;
	return ret%mod;
}		


main(){

	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
	scanf("%d",&q);
	build(0,n-1,1);

	while(q--){

		int t,a,b;
		scanf("%d%d%d",&t,&a,&b), a--, b--;

		if(t == 2)
			update(0,n-1,1,a,b);
		else
			printf("%d\n",query(0,n-1,1,a,b));

	}

}