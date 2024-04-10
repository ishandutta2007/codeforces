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

int v[maxn];

 double ans = 0;
int T, MED, K;

ll ps[maxn];

ll get(int a,int b){
	ll r = ps[b];
	if(a) r -= ps[a-1];
	return r;
}

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	sort(v,v+n);

	ps[0] = v[0];

	for(int i=1;i<n;i++)
		ps[i] = ps[i-1] + v[i];

	T = MED = K = 0;

	for(int i=1;i<n-1;i++){

		debug("i=%d\n",i);
		int low = 1, up = min(i,n-i-1);
		int t0;
		ll S;
		
		while(low != up){
			int mid = (low+up+1)/2;
		 	t0 = mid-1;
			S = get(n-t0,n-1) + get(i-t0,i-1) + v[i];
			 double cur1 = ( double)S/(2*t0+1);
			t0++;
			S = get(n-t0,n-1) + get(i-t0,i-1) + v[i];
			 double cur2 = ( double)S/(2*t0+1);
			 debug("%d : %.3lf\n",t0-1,cur1);
			 debug("%d : %.3lf\n",t0,cur2);
			if(cur1 > cur2)
				up = mid-1;
			else
				low = mid;
		}

		t0 = low;
		S = get(n-t0,n-1) + get(i-t0,i-1) + v[i];
		 double cur = ( double)S/(2*t0+1);
		 debug("-> %.3lf\n",cur);
		if(cur-v[i] > ans){
			ans = cur-v[i];
			T = 0;
			MED = i;
			K = low;
		}

	}

	for(int i=1;i<n-2;i++){

		int low = 1, up = min(i,n-i-2);
		ll S;
		int t0;

		while(low != up){
			int mid = (low+up+1)/2;
			int t0 = mid-1;
			 S = get(n-t0,n-1) + get(i-t0,i-1) + v[i] + v[i+1];
			 double cur1 = ( double)S/(2*t0+2);
			t0++;
			S = get(n-t0,n-1) + get(i-t0,i-1) + v[i] + v[i+1];
			 double cur2 = ( double)S/(2*t0+2);
			if(cur1 > cur2)
				up = mid-1;
			else
				low = mid;
		}

		t0 = low;
		S = get(n-t0,n-1) + get(i-t0,i-1) + v[i] + v[i+1];
		 double cur = ( double)S/(2*t0+2);
		if(cur-(double)(v[i]+v[i+1])/2 > ans){
			ans = cur-(double)(v[i]+v[i+1])/2;
			T = 1;
			MED = i;
			K = low;
		}

	}

	if(T == 0){
		printf("%d\n",2*K+1);
		for(int i=MED-K;i<=MED;i++)
			printf("%d ",v[i]);
		for(int i=n-K;i<n;i++)
			printf("%d ",v[i]);
		printf("\n");
	}

	else {
		printf("%d\n",2*K+2);
		for(int i=MED-K;i<=MED+1;i++)
			printf("%d ",v[i]);
		for(int i=n-K;i<n;i++)
			printf("%d ",v[i]);
		printf("\n");
	}

}