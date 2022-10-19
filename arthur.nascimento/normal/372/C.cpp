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
#define maxn 150150

using namespace std;

int dp[303][maxn];
int pr[maxn];
int sf[maxn];
int ss[maxn];

int pos[maxn];
int t[maxn];

main(){

	int n,k,d;
	scanf("%d%d%d",&n,&k,&d);

	long long ans = 0;

	for(int i=0;i<k;i++){
		int b;
		scanf("%d%d%d",pos+i,&b,t+i), pos[i]--;
		ans += b;
	}

	int cur = 0;
	int last = -1;

	while(cur < k){
	
		int f = cur;
		while(cur < n-1 && t[cur+1] == t[cur])
			cur++;
		int dt = t[cur];
		if(last != -1) dt -= t[last];
		int len = min((long long)d*dt,(long long)n);

		int mi;
		if(last+1){
			for(int i=0;i<n;i++){
				if(i%(2*len+1) == 0) mi = dp[last][i];
				else mi = min(mi,dp[last][i]);
				pr[i] = mi;
			}
			mi = dp[last][n-1];
			for(int i=n-1;i>=0;i--){
				if(i%(2*len+1) == 2*len) mi = dp[last][i];
				else mi = min(mi,dp[last][i]);
				sf[i] = mi;
			}
			mi = dp[last][n-1];
			for(int i=n-1;i>=0;i--){
				mi = min(mi,dp[last][i]);
				ss[i] = mi;
			}
		}
		debug("%d~%d\n",f,cur);

		for(int i=0;i<n;i++){
			int u = 0;
			for(int j=f;j<=cur;j++)
				u += abs(pos[j]-i);
			int l = max(0,i-len);
			int r = min(n-1,i+len);
			if(l == 0){
				dp[cur][i] = u + pr[r];
				debug("min %d..%d = %d\n",l,r,pr[r]);
			}
			else if(r == n-1)
				dp[cur][i] = u + ss[l];
			else {
				dp[cur][i] = u + min(pr[r],sf[l]);
				debug("min %d..%d = %d\n",l,r,min(pr[r],sf[l]));
			}
		}

		for(int i=0;i<n;i++)
			debug("%d ",dp[cur][i]);
		debug("\n");

		last = cur;
		cur++;
	}

	int t = inf;
	for(int i=0;i<n;i++)
		t = min(t,dp[last][i]);
	printf("%I64d\n",ans-t);

}