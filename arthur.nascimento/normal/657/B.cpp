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
#define maxn 200200

typedef long long ll;
using namespace std;


ll mod[] = {1000000007,1000000009,1000007003,1000007023,1000007027};

int p[maxn];

ll pref[maxn][5];
ll suf[maxn][5];

ll p2[maxn][5];

ll exp(ll a,ll b,ll md){
	if(b == 0)
	return 1;
	ll k = exp(a,b/2,md);
	k = (k*k)%md;
	if(b%2)
		k = (k*a)%md;
	return k;
}

ll inv(ll a,ll md){
	return exp(a%md,md-2,md);
}

ll aabs(ll x){
	if( x < 0) return -x;
	return x;
}

main(){

	int n,k;
	scanf("%d%d",&n,&k);

	for(int i=0;i<=n;i++)
		scanf("%d",p+i);

	for(int j=0;j<5;j++){
	p2[0][j] = 1;
	for(int i=1;i<=n;i++)
		p2[i][j] = (p2[i-1][j]*2) % mod[j];
	}

	for(int j=0;j<5;j++){

		pref[0][j] = p[0];

		for(int i=1;i<=n;i++)
			pref[i][j] = (pref[i-1][j] + p2[i][j]*p[i]) % mod[j];

		suf[n][j] = (p2[n][j]*p[n])%mod[j];

		for(int i=n-1;i>=0;i--)
			suf[i][j] = (suf[i+1][j] + p2[i][j]*p[i]) % mod[j];

	}

	int ans = 0;

	for(int i=0;i<=n;i++){

		ll val, val2;
		int ok = 1, ok2 = 1;
		
		for(int j=0;j<5;j++){

			ll eval = 0;
			if(i) eval += pref[i-1][j];
			if(i != n) eval += suf[i+1][j];
			eval %= mod[j];

			if(i == 10)
				debug("eval %d\n",(int)eval);

			eval = mod[j] - eval;

			ll pcur = p2[i][j];

			ll x = eval * inv(pcur,mod[j]);
			x %= mod[j];

			if(i == 1)debug("x = %d\n",(int)x);

			if(j == 0) val = x;
			else {
				if(val != x)
					ok = 0;
			}
			x = (-x+mod[j])%mod[j];
			if(i == 1)debug("x2 = %d\n",(int)x);
			if(j == 0){
				val2 = x;
			}
			else {

				if(val2 != x) ok2 = 0;
			}

		}
	
		if(ok && aabs(val) <= k){
			if(val||i!=n)ans++;debug("! %d %d\n",i,val);}
		if(!ok && ok2 && aabs(val2) <= k){
			if(val2||i!=n)ans++;debug("!! %d %d\n",i,val2);}
	
	}

	printf("%d\n",ans);

}