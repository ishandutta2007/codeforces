#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,a[301],t[301],t1,tim,f[2][300010],q[300010],l,r,mn=0x3f3f3f3f;
signed main(){
	scanf("%lld%lld%lld",&n,&m,&d);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i],&t1,&t[i]),tim+=t1;
	for(int i=1;i<=n;i++)f[1][i]=abs(a[1]-i);
	for(int ii=2;ii<=m;ii++){
		l=1,r=0;
		int i=ii&1;
		if(d*(t[ii]-t[ii-1])>=n){
			int mnm=0x3f3f3f3f;
			for(int j=1;j<=n;j++)mnm=min(mnm,f[!i][j]);
			for(int j=1;j<=n;j++)f[i][j]=mnm+abs(a[ii]-j);
			continue;
		}
//		printf("%d\n",d*(t[ii]-t[ii-1]));
		for(int j=1;j<=n+d*(t[ii]-t[ii-1])+1;j++){
			while(l<=r&&q[l]<=j-d*(t[ii]-t[ii-1])*2-1)l++;
			if(j<=n){
				while(l<=r&&f[!i][q[r]]>=f[!i][j])r--;
				q[++r]=j;
			}
			if(j>d*(t[ii]-t[ii-1]))f[i][j-d*(t[ii]-t[ii-1])]=f[!i][q[l]]+abs(a[ii]-(j-d*(t[ii]-t[ii-1])));
		}
//		for(int j=1;j<=n;j++)printf("%d ",f[i][j]);puts("");
	}
	for(int i=1;i<=n;i++)mn=min(mn,f[m&1][i]);
	printf("%I64d\n",tim-mn);
	return 0;
}