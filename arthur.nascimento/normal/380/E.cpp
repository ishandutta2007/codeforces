#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 300300

using namespace std;

int pai[2][maxn];
int foi[maxn];

int find(int x,int id){
	return pai[id][x] = (x == pai[id][x]) ? x : find(pai[id][x],id);
}

main(){

	int n;
	scanf("%d",&n);
	vector<pii> v;	
	
	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		v.pb(pii(u,i));
	}
	
	sort(v.begin(),v.end());

	for(int i=0;i<n;i++)
		pai[0][i] = pai[1][i] = i;

	double ans = 0;

	for(int i=0;i<n;i++){

		double L = 0, R = 0, x = 1;
		int p = v[i].second;
		debug("p = %d\n",p);

		if(p) pai[0][p-1] = p;
		if(p != n-1) pai[1][p+1] = p;

		debug("R ");
		for(int j=p, t=0; j < n && t < 100; t++){
			int u = find(j,0);
			R += x*(u-j+1);
			debug("%d ",u-j+1);
			x /= 2;
			j = u+1;
		}

		x = 1;

		debug("\nL ");
		for(int j=p, t=0; j >=0 && t < 100; t++){
			int u = find(j,1);
			L += x*(j-u+1);
			debug("%d ",j-u+1);
			x /= 2;
			j = u-1;
		}
		debug("\n");
		double s = L*v[i].first*R/2;
		s /= n;
		s /= n;
		ans += s;

	}

	printf("%.10lf\n",ans);

}