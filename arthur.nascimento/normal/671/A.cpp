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

#define sq(x) ((ll)(x)*(x))

int x[maxn];
int y[maxn];

double dist(int x1,int y1,int x2,int y2){
	return sqrt(sq(x1-x2)+sq(y1-y2));
}

main(){

	int x1,y1,x2,y2,xf,yf;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&xf,&yf);

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d%d",x+i,y+i);

	double ans = 0;

	for(int i=0;i<n;i++)
		ans += 2.0 * dist(x[i],y[i],xf,yf);

	vector<pfi> v1, v2;

	for(int i=0;i<n;i++){
		v1.pb(pfi(dist(x1,y1,x[i],y[i])-dist(xf,yf,x[i],y[i]),i));
		v2.pb(pfi(dist(x2,y2,x[i],y[i])-dist(xf,yf,x[i],y[i]),i));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	double d = ans;

	ans = d + v1[0].first;

	ans = min(ans, d+v1[0].first);
	ans = min(ans, d+v2[0].first);
	if(v1[0].second != v2[0].second)
		ans = min(ans, d+v1[0].first+v2[0].first);
	else if(n > 1) {
		ans = min(ans, d+v1[0].first+v2[1].first);
		ans = min(ans, d+v1[1].first+v2[0].first);
	}

	printf("%.10lf\n",ans);

}