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

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;}

int lcm(long long a,int b){
	return (a*b)/gcd(a,b);}

int exp(int a,int b,int p){
	if(b == 0) return 1;
	if(b == 1) return a;
	long long k = exp(a,b/2,p);
	k = (k*k) % p;
	if(b%2) k = (k*a) % p;
	return k;
}

int v[100100];

long long dp[2][2020][2020]; // par / mmc / pref

main(){

		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);

		vector<int> d;
		for(int i=1;i*i<=p-1;i++)
			if((p-1)%i == 0){
				d.pb(i); 
				if(i*i != p-1)
					d.pb((p-1)/i);
			}

		sort(d.begin(),d.end());

		for(int i=0;i<n;i++) scanf("%d",v+i);

		int t = 0;
		for(int i=0;i<m;i++){
			int u;
			scanf("%d",&u);
			t = gcd(u,t);
		}
		debug("t = %d\n",t);

		for(int i=0;i<n;i++)
			v[i] = exp(v[i],t,p);

		for(int i=0;i<n;i++){

			int u = v[i];
			v[i] = -1;
			for(int j=d.size()-1;j>=0;j--)
				if(exp(u,d[j],p) == 1){
					v[i] = d[j];
					debug("%d^%d=1\n",u,d[j]);
				}

		}

		debug("ok ");
		
		vector<int> a;
		sort(v,v+n);
		a.pb((p-1)/v[0]);
		debug("%d ",v[0]);
		for(int i=1;i<n;i++)
			if(v[i] != v[i-1]){
				a.pb((p-1)/v[i]);
				debug("%d ",v[i]);
			}
		debug("\n");

		n = a.size();

		map<int,int> mp;

		for(int i=0;i<d.size();i++) mp[d[i]] = i;

		sort(a.begin(),a.end());

		//dp[0][0][0] = 1;
		//dp[1][mp[a[0]]][0] = 1;
		debug("dp[%d][%d][%d] = 1\n",1,mp[a[0]],0);

		for(int i=0;i<n;i++){

			dp[1][mp[a[i]]][i]++;
			
			for(int j=0;j<d.size();j++){

				dp[0][j][i] %= p-1;
				dp[1][j][i] %= p-1;
				dp[0][j][i+1] += dp[0][j][i];
				dp[1][j][i+1] += dp[1][j][i];
				dp[0][mp[lcm(a[i+1],d[j])]][i+1] += dp[1][j][i];
				dp[1][mp[lcm(a[i+1],d[j])]][i+1] += dp[0][j][i];

			}

		}

		
		long long ans = 0;

		for(int i=0;i<d.size();i++){

			debug("div = %d %I64d par %I64d impar\n",d[i],dp[0][i][n-1],dp[1][i][n-1]);
			ans += (long long)((p-1)/d[i]) * dp[1][i][n-1] - (long long)((p-1)/d[i]) * dp[0][i][n-1];
			ans = (ans%p+p)%p;

		}

		printf("%I64d\n",ans);

}