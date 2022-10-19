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
#define maxn 100100

using namespace std;

long long fat[maxn];

long long exp(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	long long k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2)k = (k*a);
	return k%mod;
}

long long inv(long long a){
	return exp(a%mod,mod-2);
}

long long bin(int n,int k){
	if(n==k)return 1;
	if(k > n) return 0;
	return (fat[n] * inv(fat[k]*fat[n-k]))%mod;
}

char str[maxn];
int v[maxn];

long long S[maxn];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		fat[0] = 1;
		for(int i=1;i<=n;i++)
			fat[i] = (fat[i-1]*i)%mod;

		scanf(" %s",str);

		for(int i=0;i<n;i++)
			v[i] = str[i]-'0';

		for(int i=0;i<n;i++){
			long long a = bin(n-2-i,k-1) * exp(10,i);
			a%= mod;
			S[i] = a;
			if(i)
				S[i] = (S[i]+S[i-1])%mod;
		}

		long long ans = 0;

		for(int i=0;i<n;i++){

			long long u = 0;
			if(n-i-2 >=0) u = S[n-i-2];

			u += (exp(10,n-i-1) * bin(i,k)) % mod;
			u %= mod;

			debug("i=%d u=%I64d\n",i,u);

			ans = (ans + u*v[i]) % mod;

		}

		if(k == 0){
			ans = 0;
			for(int i=0;i<n;i++)
				ans = (ans*10+v[i])%mod;
		}
		cout << ans << endl;

}