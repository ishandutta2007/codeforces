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

#define inf (9999999999999999LL)
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
#define maxn 20000000

using namespace std;

long long f[22];

long long exp(long long a,long long b){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2) k = (k*a)%mod;
	return k;
}

main(){

		int n;
		long long s;
		cin >> n >> s;

		for(int i=0;i<n;i++)
			 cin >> f[i];

		long long ans = 0;

		long long fat = 1;
		for(int i=1;i<=n-1;i++)
			fat = (fat*i) % mod;

		long long inv = exp(fat,mod-2);

		for(int i=0;i<(1<<n);i++){

			long long S = 0;
			int t = 0;

			for(int j=0;j<n;j++) if(i & (1<<j)) S += f[j]+1, t++;

			if(S > s) continue;

			long long u = s - S + n - 1;

			long long pi = 1;

			for(int j=0;j<n-1;j++){
				pi = pi * ((u-j)%mod);
				pi %= mod;
			}

			pi = (pi*inv) % mod;

			if(t%2) ans -= pi;
			else ans += pi;

			ans%=mod;
			if(ans < 0) ans += mod;

		}

		cout << ans << endl;

}