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
#define max3(a,b,c) max(max(a,b),c)
#define mod 1000000007

typedef long long ll;
using namespace std;

int v[maxn];
int f[maxn];

int ans[maxn];
main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	for(int i=0;i<n;i++){
		int u = 0;
		int freq = 0;
		memset(f,0,sizeof(f));
		for(int j=i;j<n;j++){
			f[v[j]]++;
			if(f[v[j]] > freq || (f[v[j]] == freq && v[j] < u))
				u = v[j];
			freq = f[u];
			ans[u]++;
		}
	}

	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);

}