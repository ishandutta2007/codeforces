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
int w[maxn];

main(){

	int n,k;
	scanf("%d%d",&n,&k);

	if(k <= n || n == 4){
		printf("-1\n");
		return 0;
	}
//cout << "Ok";
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);//cout << "!";
	//debug("%d\n",n);
	v[1] = a; v[n] = b; v[2] = c; v[n-1] = d;
	w[a]=w[b]=w[c]=w[d]=1;//cout << "Ok";
	int pos = 3;
	for(int i=1;i<=n;i++)
		if(!w[i]){
			v[pos] = i;
			pos++;
		}

	vector<int> x, y;

	for(int i=1;i<=n;i++)
		x.pb(v[i]);
//return 0;
	y.pb(v[2]);
	y.pb(v[1]);
	for(int i=3;i<=n-2;i++)
		y.pb(v[i]);
	y.pb(v[n]);
	y.pb(v[n-1]);
//return 0;
	for(int i=0;i<n;i++){
		int u = x[i];
		printf("%d ",u);
	}
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",y[i]);
	printf("\n");

}