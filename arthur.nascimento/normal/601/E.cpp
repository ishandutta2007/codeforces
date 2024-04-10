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
#define p 10000019
#define q 1000000007
#define maxn 100100

typedef long long ll;
using namespace std;

int val[maxn];
int w[maxn];
int in[maxn];
int out[maxn];

int tipo[maxn];
int id[maxn];

int k;

int cur[1010];
int aux[20][1010];

void go(int l,int r,int lvl){

	if(l == r){
		if(tipo[l] != 3)
			return;
		ll ans = 0;
		ll u = 1;
		for(int i=1;i<=k;i++){
			ans += u * cur[i];
			u *= p;
			ans %= q;
			u %= q;
		}
		for(int i=1;i<=k;i++)
			debug("%d ",cur[i]);
		debug("\n");
		printf("%lld\n",ans);
		return;
	}

	int mid = (l+r)/2;

	for(int i=0;i<=k;i++)
		aux[lvl][i] = cur[i];

	for(int i=mid+1;i<=r;i++)
		if(tipo[i] == 2 && in[id[i]] < l)
			for(int j=k;j>=w[id[i]];j--)
				cur[j] = max(cur[j],cur[j-w[id[i]]]+val[id[i]]);

	go(l,mid,lvl+1);

	for(int i=0;i<=k;i++)
		cur[i] = aux[lvl][i];

	for(int i=l;i<=mid;i++)
		if(tipo[i] == 1 && out[id[i]] > r)
			for(int j=k;j>=w[id[i]];j--)
				cur[j] = max(cur[j],cur[j-w[id[i]]]+val[id[i]]);
		
	go(mid+1,r,lvl+1);

}

main(){

	int n;
	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)
		scanf("%d%d",val+i,w+i), in[i] = i, tipo[i] = 1, id[i] = i;

	int d;
	scanf("%d",&d);

	int qnt = n;

	for(int i=n;i<n+d;i++){

		int t;
		scanf("%d",&t);

		tipo[i] = t;

		if(t == 1){
			scanf("%d%d",val+qnt,w+qnt);
			in[qnt] = i;
			id[i] = qnt;
			qnt++;
		}

		if(t == 2){
			int u;
			scanf("%d",&u), u--;
			id[i] = u;
			out[u] = i;
		}

	}

	n += d;

	for(int i=0;i<qnt;i++)
		if(out[i] == 0){
			tipo[n] = 2;
			id[n] = i;
			out[i] = n++;
		}

	go(0,n-1,0);

}