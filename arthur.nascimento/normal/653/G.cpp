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
#define mod 1000000007

typedef long long ll;
using namespace std;

vector<int> v[maxn];

int sobe[20];
int desce[20];

int qt0[20];
int qt1[20];

ll fat[maxn];

ll exp(ll a,ll b){
	if(b == 0)
		return 1;
	ll r = exp(a,b/2);
	r = (r*r)%mod;
	if(b%2)
		r = (r*a)%mod;
	return r;
}

ll inv(ll a){
	return exp(a%mod,mod-2);
}

ll C(int n,int k){
	if(n < 0 || k < 0 || k > n)
		return 0;
	ll r = (fat[n] * inv(fat[k]*fat[n-k])) % mod;
	return r;
}

ll mul(ll a,ll b){
	debug("mul %lld %lld\n",a,b);
	a %= mod;
	if(a < 0) a += mod;
	b %= mod;
	if(b < 0) b += mod;
	return (a*b)%mod;
}

ll s[maxn];
ll ps[maxn];

ll get(int a,int b){
	if(a > b)
		return 0;
	ll r = ps[b];
	if(a) r -= ps[a-1];
	debug("get %d..%d = %lld\n",a,b,r);
	return r;
}

main(){

	int n;
	scanf("%d",&n);

	fat[0] = 1;
	for(int i=1;i<maxn;i++)
		fat[i] = (fat[i-1]*i)%mod;
		

	for(int i=0;i<n;i++){

		int a;
		scanf("%d",&a);

		for(int j=2;j*j<=a;j++)
			if(a%j == 0){
				int q = 0;
				while(a%j == 0){
					a /= j;
					q++;
				}
				v[j].pb(q);
			}
		if(a != 1)
			v[a].pb(1);

	}

	ll ans = 0;

	for(int i=0;i<maxn;i++){
		sort(v[i].begin(),v[i].end());
		int u = n-1;
		for(int j=(int)v[i].size()-1;j>=0;j--){
			s[u] += v[i][j];
			s[u] %= mod;
			u--;
		}
	}

	ps[0] = s[0];
	for(int i=1;i<maxn;i++)
		ps[i] = (ps[i-1]+s[i])%mod;
	

	for(int i=0;i<n;i++){

		debug("i=%d\n",i);

		int A = i;
		int B = n-i-1;
		
		ans += mul(get(i+1,n-1) - (ll) B * get(i,i), C(n-2,B));
		ans %= mod;

		ans += mul((ll) A * get(i,i) - get(0,i-1), C(n-2,A));
		ans %= mod;

		ans += mul(get(i+1,n-1) - (ll) B * get(i,i), C(n-2,B-1));
		ans %= mod;

		ans += mul((ll) A * get(i,i) - get(0,i-1), C(n-2,B-2));
		ans %= mod;

	}
	
	cout << ans << endl;

}