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
#define maxn 100100

using namespace std;

pll v[maxn];

long long ps[maxn];

long long get(int a,int b){
	if(a > b)
		return 0;
	long long ret = ps[b];
	if(a)
		ret -= ps[a-1];
	return ret;
}

long long ans = 0;
int besti, bestlow=23;
void reg(long long A,int i,int l){
	if(A > ans){
		ans = A;
		besti = i;
		bestlow = l;
	}
}

int print[maxn];

main(){

	int n;
	int qmax;
	long long x, y, k;
	cin >> n >> qmax >> x >> y >> k;

	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		v[i] = pll(u,i);
	}

	sort(v,v+n);
	reverse(v,v+n);

	ps[0] = v[0].first;
	for(int i=1;i<n;i++)
		ps[i] = ps[i-1] + v[i].first;
	

	for(int i=0;i<=n;i++){

		//if(i < n && v[i].first == qmax)
			//continue;
		long long add = (long long) qmax * i;
		add -= get(0,i-1);
		if(add > k)
			continue;
		long long r;
	
		if(i == n){
			r = x * n + y * qmax;
			reg(r,i,qmax);
			continue;
		}

		debug("i=%d\n",i);

		int low = 0, up = qmax-1;
		int low2, up2;
		while(low != up){
			int mid = (low+up+1)/2;
			 low2=0, up2=n-1;
			while(low2 != up2){
				int mid2 = (low2+up2)/2;
				if(v[mid2].first <= mid)
					up2 = mid2;
				else
					low2 = mid2+1;
			}
			low2 = max(low2,i);
			if(v[n-1].first > mid)
				low2 = n;
			long long U = (long long) mid * (n-1-low2+1) - get(low2,n-1);
			if(mid == 502 && i == 0 && x == 51 && y == 60)
				printf("U %I64d add %I64d k %I64d\n",U,add,k);
			if(U + add <= k)
				low = mid;
			else
				up = mid-1;
		}
		debug("low %d\n\n",low);

		reg(x * i + y * low, i, low);

	}

	printf("%I64d\n",ans);
	if(ans == 30120)
		printf("%d %d\n",besti,bestlow);

	for(int i=0;i<n;i++){
		if(i < besti)
			print[v[i].second] = qmax;
		else
			print[v[i].second] = max(bestlow,(int)v[i].first);;
	}

	for(int i=0;i<n;i++)
		printf("%d ",print[i]);
	printf("\n");
}