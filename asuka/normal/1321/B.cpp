#include<bits/stdc++.h>
#define int long long
#define N 400015
using namespace std;
int n,b[N],sum[N<<1],minn,maxx,ans;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	minn = 0x3f3f3f3f;
	for(int i = 1;i <= n;++i){
		scanf("%lld",&b[i]);
		sum[N+b[i]-i] += b[i];
		minn = min(minn,N+b[i]-i);
		maxx = max(maxx,N+b[i]-i);
	}
	for(int i = minn;i <= maxx;++i) ans = max(ans,sum[i]);
	printf("%lld",ans);
	return 0;
}