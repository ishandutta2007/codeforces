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
#define maxn 500500
#define mod 1000000007

typedef long long ll;
using namespace std;

int v[maxn];
int b[maxn];

int z(int i,int a,int b){
	if(i%2 == 0)
		return (a>=b)?1:0;
	else
		return (a<=b)?1:0;
}

int check(int n){
	int bad = 0, j;
	for(int i=0;i<n-1;i++){
		if(i%2 == 0 && b[i] >= b[i+1])
			j = i, bad++;
		if(i%2 == 1 && b[i] <= b[i+1])
			j = i, bad++;
	}
	if(bad)return 0;
	return 1;
}

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	int j = 0;
	int bad = 0;
	for(int i=0;i<n-1;i++){
		if(i%2 == 0 && v[i] >= v[i+1])
			j = i, bad++;
		if(i%2 == 1 && v[i] <= v[i+1])
			j = i, bad++;
	}

	int ans = 0;

	for(int u=j;u<j+2;u++){
		for(int i=0;i<n;i++)
			if(i != j && i != j+1){
				if(abs(i-u) < 5){
					for(int k=0;k<n;k++)
						b[k] = v[k];
					swap(b[u],b[i]);
					if(check(n)) ans++;
					continue;
				}
				int b0 = bad;
				if(i != n-1)b0 -= z(i,v[i],v[i+1]);
				if(i)b0 -= z(i-1,v[i-1],v[i]);
				if(u != n-1)b0 -= z(u,v[u],v[u+1]);
				if(u)b0 -= z(u-1,v[u-1],v[u]);
				if(i != n-1)b0 += z(i,v[u],v[i+1]);
				if(i)b0 += z(i-1,v[i-1],v[u]);
				if(u != n-1)b0 += z(u,v[i],v[u+1]);
				if(u)b0 += z(u-1,v[u-1],v[i]);
				if(b0 == 0){
					ans++;
					debug("%d %d\n",i,u);
				}
			}
	}

	swap(v[j],v[j+1]);

	bad = 0;
	for(int i=0;i<n-1;i++){
		if(i%2 == 0 && v[i] >= v[i+1])
			j = i, bad++;
		if(i%2 == 1 && v[i] <= v[i+1])
			j = i, bad++;
	}
	if(bad == 0)ans++;
	cout << ans << endl;

}