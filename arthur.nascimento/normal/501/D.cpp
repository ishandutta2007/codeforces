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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 400400

using namespace std;

int T[3][maxn];

int query(int idx,int id){
	int ret = 0;
	idx++;
	while(idx){
		ret += T[id][idx];
		idx -= idx&-idx;
	}
	return ret;
}

void update(int idx,int val,int id){
	idx++;
	while(idx < maxn){
		T[id][idx] += val;
		idx += idx&-idx;
	}
}

int search(int id,int val){
	int ret = 0;
	for(int i=18;i>=0;i--)
		if(T[id][ret+(1<<i)] <= val){
			val -= T[id][ret+(1<<i)];
			ret += 1 << i;
		}
	return ret;
}

int v[maxn];

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		update(i,1,0), update(i,1,1), update(i,1,2);
	
	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		update(u,-1,0);
		v[i] += query(u,0);
	}

	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		update(u,-1,1);
		v[i] += query(u,1);
	}

	for(int i=n-1;i>=0;i--){
		int t = n-i;
		if(i) v[i-1] += v[i]/t;
		v[i] %= t;
	}

	for(int i=0;i<n;i++)
		debug("v[%d] = %d\n",i,v[i]);

	for(int i=0;i<n;i++){
		int u = search(2,v[i]);
		printf("%d ",u);
		update(u,-1,2);
	}

	printf("\n");

}