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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 7340033
#define maxn 100100

using namespace std;

const int r = 3;

long long exp(long long a,int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2);
	k = (k*k) % mod;
	if(b%2) k = (k*a)%mod;
	return k;
}

long long pot[10100];
long long pot2[10100];

int P[100100];
int aa[100100];
int len;

int dft(int p0,int n,int skip) {

	if(n == 1) {
		aa[len++] = P[p0];
	 	return len-1;
	}

	int pa = dft(p0,n>>1,skip<<1);
	int pb = dft(p0+skip,n>>1,skip<<1);

	int ret = len;

	int n2 = n>>1;
	for(int i=0;i<n2;i++)
	
		aa[len++] = (aa[pa+i] + pot[i*skip] * aa[pb+i])%mod;

	for(int i=n2;i<n;i++)
	
		aa[len++] = (aa[pa+i-n2] + pot[i*skip] * aa[pb+i-n2]) % mod;

	return ret;

}

int dft_inverse(int p0,int n,int skip) {

	if(n == 1) {
		aa[len++] = P[p0];
	 	return len-1;
	}

	int pa = dft_inverse(p0,n>>1,skip<<1);
	int pb = dft_inverse(p0+skip,n>>1,skip<<1);

	int ret = len;

	int n2 = n>>1;
	for(int i=0;i<n2;i++)
	
		aa[len++] = (aa[pa+i] + pot2[i*skip] * aa[pb+i])%mod;

	for(int i=n2;i<n;i++)
	
		aa[len++] = (aa[pa+i-n2] + pot2[i*skip] * aa[pb+i-n2]) % mod;

	return ret;



}

vector<int> square(vector<int> poly,int t){

	//while(poly.size() > t) poly.pop_back();

	int n = 2*poly.size();
	while(n != (n&-n))n++;
	while(poly.size() < n)poly.pb(0);
	
	int inv = exp(n,mod-2);

	int s = exp(r,(mod-1)/n);
	int invs = exp(s,mod-2);

	pot[0] = 1;
	for(int i=1;i<=n;i++)
		pot[i] = (pot[i-1] * s) % mod;

	pot2[0] = 1;
	for(int i=1;i<=n;i++)
		pot2[i] = (pot2[i-1] * invs) % mod;

	len = 0;

	for(int i=0;i<n;i++) P[i] = poly[i];
	int y = dft(0,n,1);
	vector<int> a;
	for(int i=0;i<n;i++)
		a.pb(aa[y+i]);

	for(int i=0;i<n;i++)
		a[i] = ((long long)a[i]*a[i]) % mod;

	len = 0;
	for(int i=0;i<n;i++) P[i] = a[i];
	y = dft_inverse(0,n,1);
	vector<int> b;
	for(int i=0;i<n;i++)
		b.pb(aa[y+i]);

	for(int i=0;i<n;i++)
		b[i] = ((long long)b[i] * inv) % mod;

	return b;

}

vector<int> fix(vector<int> poly){

	vector<int> ret;
	ret.pb(1);
	for(int i=0;i<min(1000,(int)poly.size());i++)
		ret.pb(poly[i]);
	return ret;

}

vector<int> ans[33];

main(){

	/*
		vector<int> d;
		for(int i=1;i<mod-1;i++)
			if((mod-1)%i == 0){printf("+%d ",i);d.pb(i);}

		for(int i=1;i<mod;i++){

			int ok = 1;
			for(int j=0;j<d.size() && ok;j++)
				if(exp(i,d[j]) == 1)
					ok = 0;

			if(ok)
				printf("%d\n",i);

		}										*/


		vector<int> v;
		v.pb(1);
		ans[0] = v;

		for(int i=1;i<33;i++){
			ans[i] = fix(square(square(ans[i-1],1001),1001));
		}

		int q;
		scanf("%d",&q);

		while(q--){

			int n,k;
			scanf("%d%d",&n,&k);
			int u = 0;
			while((n&1) && n>=3) u++, n >>= 1;
			debug("u = %d\n",u);
			if(ans[u].size() <= k)
				printf("0\n");
			else
				printf("%d\n",ans[u][k]);

		}

}