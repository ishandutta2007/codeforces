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

#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pfi pair<double,int>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 500500
#define max3(a,b,c) max(max(a,b),c)
#define mod 1000000007
typedef long long ll;
using namespace std;

int v[maxn];

main(){

	int n;
	ll k, s = 0;
	cin >> n >> k;

	for(int i=0;i<n;i++)
		scanf("%d",v+i), s += v[i];

	sort(v,v+n);

	ll inf = s/n;
	ll sup = inf+(s%n!=0);

	if(inf == sup){
		ll u = 0;
		for(int i=0;i<n;i++)
			if(v[i] > inf) u += v[i]-inf;
		debug("u %lld inf %lld k %lld\n",u,inf,k);
		if(u <= k){
			printf("0\n");
			return 0;
		}
	}	

	int up = n-1;
	ll cur = 1;
	ll aux = k;

	while(up >= 1 && v[up-1] >= sup && cur*(v[up]-v[up-1]) <= aux){
		aux -= cur*(v[up]-v[up-1]);
		cur++;
		up--;
	}
	ll B = v[up] - aux/cur;
	if(B < sup)
		B = sup;

	int low = 0;
	cur = 1;
	aux = k;

	while(low <= n-2 && v[low+1] <= inf && cur*(v[low+1]-v[low]) <= aux){
		aux -= cur*(v[low+1]-v[low]);
		cur++;
		low++;
	}
	ll A = v[low] + aux/cur;
	if(A > inf)
		A = inf;

	cout << B-A << endl;

}