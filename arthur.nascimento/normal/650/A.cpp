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
#define maxn 100100

typedef long long ll;
using namespace std;

map<pii,int> mp;

main(){
	
	int n;
	scanf("%d",&n);
	
	ll ans = 0;
	
	vector<pii> v,v2;
	
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ans -= mp[pii(x,y)];
		mp[pii(x,y)]++;
		v.pb(pii(x,y));
		v2.pb(pii(y,x));
	}
	
	sort(v.begin(), v.end());

	int p = 0;
	while(p < n){
		int p0 = p;
		while(p < n && v[p0].first == v[p].first)
			p++;
		ll qnt = p-p0;
		ans += (qnt*qnt-qnt)/2;
	}
	
	sort(v2.begin(), v2.end());
	
	 p = 0;
	 
	while(p < n){
		int p0 = p;
		while(p < n && v2[p0].first == v2[p].first)
			p++;
		ll qnt = p-p0;
		ans += (qnt*qnt-qnt)/2;
	}
	
	cout << ans << endl;
	
}