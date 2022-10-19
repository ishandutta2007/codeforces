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
#define maxn 100100

#define max3(a,b,c) max(max(a,b),c)

typedef long long ll;
using namespace std;

main(){

	int n;
	scanf("%d",&n);

	vector<pii> vx, vy;

	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vx.pb(pii(x,y));
		vy.pb(pii(y,x));
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	for(int i=0;i<n;i++)
		swap(vy[i].first, vy[i].second);

	ll ans = 0;

	for(int i=0;i<n/2;i++)
		ans -= vx[i].first+vy[i].second;
		
	for(int i=(n+1)/2;i<n;i++)
		ans += vx[i].first+vy[i].second;

	double xm, ym;
	int a=0, b=0;
	ll u = 0;
		
	if(n%2 == 1){
		if(vx[n/2] == vy[n/2]){

			xm = 0.5 * (vx[n/2-1].first+vx[n/2].first);
			ym = 0.5 * (vy[n/2-1].second+vy[n/2].second);

			for(int i=0;i<n;i++){
				if(vx[i].first <= xm && vx[i].second <= ym) a++;
				else if(vx[i].first >= xm && vx[i].second >= ym) a++;
				if(vx[i].first <= xm && vx[i].second >= ym) b++;
				else if(vx[i].first >= xm && vx[i].second <= ym) b++;
			}

			if(a == n || b == n){
				printf("%lld\n",2*ans);
				return 0;
			}

			u = 2*ans + max(max(2*vy[n/2].second - 2*vy[n/2+1].second,-2*vy[n/2].second + 2*vy[n/2-1].second),max(2*vx[n/2].first - 2*vx[n/2+1].first,-2*vx[n/2].first + 2*vx[n/2-1].first));
			
		
			for(int i=n/2+1;i<n;i++){
				swap(vx[i-1],vx[i]);
				swap(vy[i-1],vy[i]);
			}
			vx.pop_back();
			vy.pop_back();
			n--;
		}
		else {
			printf("%lld\n",2*ans);
			return 0;
		}
	}

	xm = 0.5 * (vx[n/2-1].first+vx[n/2].first);
	ym = 0.5 * (vy[n/2-1].second+vy[n/2].second);

	a = b = 0;

	for(int i=0;i<n;i++){
		if(vx[i].first <= xm && vx[i].second <= ym) a++;
		else if(vx[i].first >= xm && vx[i].second >= ym) a++;
		if(vx[i].first <= xm && vx[i].second >= ym) b++;
		else if(vx[i].first >= xm && vx[i].second <= ym) b++;
	}

	if(a == n || b == n)
		printf("%lld\n",2*ans);
	else
		printf("%lld\n",max3(u,2*ans+2*vx[n/2-1].first-2*vx[n/2].first, 2*ans+2*vy[n/2-1].second-2*vy[n/2].second));

}