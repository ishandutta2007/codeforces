#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b) ; ++i)
int main(){
	int n,a;
	scanf("%d",&n);
	bool b[(int)1e6+10] = {};
	rep(i,0,n)
		scanf("%d",&a),
		b[a] = 1;
	int dp[(int)1e6+10] = {};
	rep(i,0,(int)1e6+1)
		if(b[i])
			for(int j = 2*i; j <= (int)1e6; j+=i)
				dp[j] = max(dp[j], 1+dp[i]);
	int ans = 0;
	rep(i,0,(int)1e6+1)
		if(b[i])
			ans = max(ans, dp[i]);
	printf("%d\n",ans+1);
}