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

#define inf (999999999999LL)
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
#define mod 1000000007
#define maxn 10100

using namespace std;

long long v[maxn];

long long gcd(long long a,long long b){
	return b ? gcd(b,a%b) : a;}

long long pk[maxn];

long long p[maxn];
long long a[maxn];

map<long long,long long> phi;

long long mt(long long a,long long b,long long md){
	if(b == 0) return 0;
	if(b == 1) return a;
	long long k = mt(a,b/2,md);
	k = (2*k)%md;
	if(b%2) k = (k+a)%md;
	return k;
}

long long exp(long long a,long long b,long long md){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2,md);
	k = mt(k,k,md);
	if(b%2) k = mt(k,a,md);
	return k;
}

main(){

		long long n,m,k;
		cin >> n >> m >> k;

		long long lcm = 1;
		int imp = 0;

		for(int i=0;i<k;i++){
			cin >> v[i];
			long long u = v[i] / gcd(v[i],lcm);
			if(log(lcm) + log(u) > 15*log(10)) imp = 1;
			lcm *= u;
			if(lcm > n) imp = 1;
		}

		int q = 0;
		debug("lcm = %I64d\n",lcm);
		long long lcm0 = lcm;
		
		for(long long i=2;i*i<=lcm;i++) if(lcm%i == 0){
			p[q] = i;
			long long u = 1;
			while(lcm%i == 0) lcm /= i, a[q]++, u *= i;
			phi[u] = u / i;
			phi[u] *= (i-1);
			pk[q] = u;
			q++;
		}

		if(lcm){
			phi[lcm] = lcm-1;
			p[q] = lcm;
			pk[q] = lcm;
			a[q] = 1;
			q++;
			lcm = 1;
		}

		for(int i=0;i<k;i++) 
			for(int j=0;j<q;j++)
				if(v[i] % pk[j] == 0)
					a[j] = ((-i)%pk[j]+pk[j])%pk[j];

		for(int i=0;i<q;i++)
			debug("x = %I64d (mod %I64d)\n",a[i],pk[i]);
		
		long long A = a[0];
		long long P = pk[0];

		for(int i=1;i<q;i++){
			//A = mt(A-a[i],exp(pk[i],P-1,P*pk[i]),P*pk[i]) + a[i];
			//long long m = mt(A-a[i],exp(pk[i],P-2,P),P) ;
			//A = mt(pk[i],m,P*pk[i]);
			//A += a[i];
			debug("phi[%I64d] = %I64d\n",P,phi[P]);
			debug("phi[%I64d] = %I64d\n",pk[i],phi[pk[i]]);
			A = mt(A,exp(pk[i],phi[P],P*pk[i]),P*pk[i]) + mt(a[i],exp(P,phi[pk[i]],P*pk[i]),P*pk[i]);
			A %= (P*pk[i]);
			long long u = phi[P] * phi[pk[i]];
			P *= pk[i];
			phi[P] = u;
			A = (A%P+P)%P;
			debug("A = %I64d P = %I64d\n",A,P);
			//assert(A%32 == 0);
		}

		debug("x = %I64d\n",A);
		if(A == 0) A = P;
		assert(P == lcm0);

		for(int i=0;i<q;i++){
			debug("x = %I64d (mod %I64d)\n",a[i],pk[i]);
			//cout << A%pk[i] << endl;
			assert(A%pk[i] == a[i]);
		}
		
		for(int i=0;i<k;i++)
			if(v[i] != gcd(lcm0,A+i) || A+i > m) imp = 1;

		if(imp == 0)
			printf("YES\n");
		else
			printf("NO\n");

}