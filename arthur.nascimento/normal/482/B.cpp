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
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int T[4*maxn];
int lazy[4*maxn];

int t1 = (1<<31) - 1;

void refresh(int init,int fim,int p){

	T[p] |= lazy[p];
	int mid = (init+fim)/2;
	if(init != fim){
		lazy[2*p] |= lazy[p];
		lazy[2*p+1] |= lazy[p];
	}

}

void update(int init,int fim,int l,int r,int p,int val){

	refresh(init,fim,p);

	if(l > fim || r < init) return;

	if(init >= l && fim <= r){
		lazy[p] |= val;
		refresh(init,fim,p);
		return;
	}

	int mid = (init+fim)/2;
	update(init,mid,l,r,2*p,val);
	update(mid+1,fim,l,r,2*p+1,val);

	T[p] = T[2*p] & T[2*p+1];

}

int query(int init,int fim,int p,int l,int r){

	refresh(init,fim,p);

	if(l > fim || r < init) return t1;

	if(init >= l && fim <= r)
		return T[p];

	int mid = (init+fim)/2;

	int ret = query(init,mid,2*p,l,r) & query(mid+1,fim,2*p+1,l,r);

	T[p] = T[2*p] & T[2*p+1];

	return ret;

}

int L[maxn];
int R[maxn];
int V[maxn];

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		for(int i=0;i<q;i++){
			scanf("%d%d%d",L+i,R+i,V+i), L[i]--, R[i]--;
			update(0,n-1,L[i],R[i],1,V[i]);
		}

		int ok = 1;
		for(int i=0;i<q;i++){
			int u = query(0,n-1,1,L[i],R[i]);
			if(u != V[i]) ok = 0;
		}

		if(!ok){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");

		for(int i=0;i<n;i++)
			printf("%d ",query(0,n-1,1,i,i));

		printf("\n");

}