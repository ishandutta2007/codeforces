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

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define pcc pair<char,char>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 1200000	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

main(){

	int q;
	scanf("%d",&q);

	map<ll,ll> mp;

	while(q--){

		int t;
		scanf("%d",&t);

		if(t == 1){
			ll a, b, p;
			scanf("%I64d%I64d%I64d",&a,&b,&p);
			while(a != b){
				if(a < b) swap(a,b);
				mp[a] += p;
				a /= 2;
			}
		}
		else {
			ll a, b;
			ll  ans = 0;
			scanf("%I64d%I64d",&a,&b);
			while(a != b){
				if(a < b) swap(a,b);
				ans += mp[a];
				a /= 2;
			}
			cout << ans << endl;
		}

	}

}