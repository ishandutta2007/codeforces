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
#define maxn 300300

typedef long long ll;
using namespace std;

int v[maxn];

main(){

	int n;
	scanf("%d",&n);

	vector<int> va,vb;

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	int u = 0;
	while(v[u] != 1)u++;

	va.pb(1);
	for(int i=(u+1)%n;i!=u;i=(i+1)%n)
		if(v[i])va.pb(v[i]);
		
	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	u = 0;
	while(v[u] != 1) u++;

	vb.pb(1);
	for(int i=(u+1)%n;i!=u;i=(i+1)%n)
		if(v[i])vb.pb(v[i]);

	int ok = 1;
	for(int i=0;i<n-1;i++)
		if(va[i] != vb[i])
			ok = 0;

	printf("%s\n",ok?"YES":"NO");
}