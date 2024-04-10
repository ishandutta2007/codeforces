#include <iostream>
#include <assert.h>
#include <cmath>
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

#define inf 1000000
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300
//#define mod 1000000007

#define time ofuherf

typedef long long ll;
using namespace std;

int ans[50500];
int v[50500];

int go(int k,int n){

	map<int,int> foi;
	
	for(int i=0;i<n;i++){

		int a = v[i];
		while(a > k) a /= 2;
		while(foi[a] && a != 0) a /= 2;
		if(a == 0) return 0;
		ans[i] = a;
		foi[a] = 1;

	}

	return 1;

}

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	int low = 1, up = (int)1e9+10;

	while(low != up){
		int mid = (low+up)/2;
		if(go(mid,n))
			up = mid;
		else
			low = mid+1;
	}

	go(low,n);
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");

}