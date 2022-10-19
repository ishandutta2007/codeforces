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

#define inf 1000000
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 3030
#define mod 1000000007

#define time ofuherf

typedef long long ll;
using namespace std;


ll meet[maxn][maxn];
ll dp[maxn][maxn];

int v[maxn];

ll macc[maxn][maxn];

ll acc(int a,int b){
	if(a == -1) return 0;
	if(macc[a][b]+1)
		return macc[a][b];
	return macc[a][b] = acc(a-1,b) + abs(v[a] - (v[b] - (b-a)));
}

ll getm(int a,int b){
	
	if(meet[a][b]+1)
		return meet[a][b];
	if(a == b)
		return 0;
	ll r = acc(b,b) - acc(a-1,b);
//	debug("meet %d %d = %lld\n",a,b,r);
	return r;
}

ll suf[maxn];

main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
		
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			meet[i][j] = -1;
			macc[i][j] = -1;
		}
			
	for(int i=0;i<n;i++)
		dp[i][n] = 0;
			
	for(int i=n-1;i>=0;i--){
		
		vector<pll> opt;
		
	//	debug("i = %d\n",i);
		
		for(int j=i;j<n;j++){
			opt.pb(pll(v[j]-(j-i),getm(i,j) + dp[j][j+1]));
		//	debug("j = %d add %lld (%lld)\n",j,	getm(i,j) + dp[j][j+1], (ll)v[j]-(j-i));
		}
			
		sort(opt.begin(), opt.end());
		
		suf[opt.size()-1] = opt[opt.size()-1].second;
		
		for(int j=opt.size()-2;j>=0;j--)
			suf[j] = min(suf[j+1], opt[j].second);
		
		for(int j=0;j<i;j++){
			
			int k = v[j] + (i-j);
			
			dp[j][i] = abs(v[i]-k) + dp[j][i+1];
			
			int low = 0, up = opt.size()-1;
			
			if(k > opt[up].first){
				//debug("! dp[%d][%d] = %lld\n",j,i,dp[j][i]);
				continue;
			}
			
			while(low != up){
				int mid = (low+up)/2;
				if(opt[mid].first >= k)
					up = mid;
				else
					low = mid+1;
			}
			
			dp[j][i] = min(dp[j][i], suf[low]);
			//debug("dp[%d][%d] = %lld\n",j,i,dp[j][i]);
			
		}
		
	}
	
	int ok = 1;
	for(int i=1;i<n;i++){
		if(v[i] <= v[i-1])
			ok = 0;
	}
	
	if(ok){
		printf("0\n");
		return 0;
	}
	
	ll ans = 1ll << 60;
	
	for(int i=0;i<n;i++){
		ans = min(ans, getm(0,i) + dp[i][i+1]);
		//if(ans == 8) debug("!! %d\n",i);
	}
		
	cout << ans << endl;
	
}