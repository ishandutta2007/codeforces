#include<cstdio>
#include<algorithm>
#include<utility>
#define N 100100
#define F first
#define S second
using namespace std;
pair<int,int> p[N];
int dp[N];
int main(){
	int n,ans;
	scanf("%d",&n);
	ans=n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].F,&p[i].S);
	}
	sort(p,p+n);
	dp[0]=0;
	for(int i=1;i<n;i++){
		int pre=lower_bound(p,p+n,make_pair(p[i].F-p[i].S,0))-p;
		if(pre==0) dp[i]=i;
		else dp[i]=dp[pre-1]+i-pre;
	}
	for(int i=0;i<n;i++){
		if(dp[i]+(n-i-1)<ans) ans=dp[i]+(n-i-1);
	}
	printf("%d\n",ans);
	return 0;
}