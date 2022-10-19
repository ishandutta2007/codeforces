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
#define pdi pair<double,int>
#define eps 1e-9


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100
#define sq(x) ((long long)(x)*(x))
using namespace std;
typedef long long ll;

int pref[maxn];
int Pref[maxn];
int Suf[maxn];
int suf[maxn];

main(){

	int n;
	scanf("%d",&n);

	vector<pii> v;

	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v.pb(pii(x,y));
	}

	sort(v.begin(), v.end());

	pref[0] = Pref[0] = v[0].second;
	for(int i=1;i<n;i++){
		pref[i] = min(pref[i-1], v[i].second);
		Pref[i] = max(Pref[i-1], v[i].second);
	}
	suf[n-1] = Suf[n-1] = v[n-1].second;
	for(int i=n-2;i>=0;i--){
		suf[i] = min(suf[i+1], v[i].second);
		Suf[i] = max(Suf[i+1], v[i].second);
	}	

	ll ans = sq(v[n-1].first-v[0].first);

	for(int i=0;i<n;i++){

		int x = v[i].first, y = v[i].second;

		ll low = 0, up = ans;

		while(low != up){

			ll mid = (low+up)/2;
			if(mid < sq(y)){
				low = mid+1;
				continue;
			}
			ll u = (ll) sqrt(mid);
			while(sq(u) > mid) u--;
			while(sq(u+1) <= mid) u++;
			
			ll ymax = y, ymin = y - u;
			ymin = max(ymin,-ymax);

			if(y < 0){
				ymin = y;
				ymax = y + u;
				ymax = min(ymax,-ymin);
			}

			ll d = u;
			u = (ll) sqrt(mid-sq(y));
			while(sq(u) > mid-sq(y)) u--;
			while(sq(u+1) <= mid-sq(y)) u++;
			ll xmax = u, xmin = -u;

			debug("i %d mid %lld x %lld~%lld y %lld~%lld\n",i,mid,xmin,xmax,ymin,ymax);

			int ok = 1;

			if(Pref[n-1] > ymax || pref[n-1] < ymin){
		
				int a = 0, b = n-1;
				while(a != b){
					int m = (a+b)/2;
					if(Pref[m] > ymax || pref[m] < ymin)
						b = m;
					else
						a = m+1;
				}
				int l1 = a;
				a = 0, b = n-1;
				while(a != b){
					int m = (a+b+1)/2;
					if(Suf[m] > ymax || suf[m] < ymin)
						a = m;
					else
						b = m-1;
				}
				int l2 = a;
				if(v[l1].first < xmin || v[l2].first > xmax || v[l2].first-v[l1].first > d)
					ok = 0;
			}

			if(ok)
				up = mid;
			else
				low = mid+1;

		}

		ans = low;

	}

	for(int i=0;i<n;i++)
		swap(v[i].first,v[i].second);
		
	sort(v.begin(), v.end());

	ans = min(ans, sq(v[n-1].first-v[0].first));

	printf("%lld\n",ans);

}