#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,a[N],lb[N],rb[N];
long long dp[N][2];
bool fl[N];
struct L{
	int l,r;
	bool operator<(L a)const{return r<a.r;}
}p[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k,t;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=m;++i)cin>>p[i].l>>p[i].r;
		sort(p+1,p+m+1),t=0,j=-2e9;
		for(i=1;i<=m;++i){
			if(p[i].l>j)j=max(j,p[i].l),p[++t]=p[i];
		}
		m=t,j=1,t=0;
		for(i=1;i<=m;++i){
			while(j<=n&&a[j]<p[i].l)++j;
			if(j>n||a[j]>p[i].r)p[++t]=p[i];
		}
		m=t,j=1;
		memset(lb,9,n*4+4),memset(rb,-9,n*4+4),memset(fl,0,n+1);
		for(i=1;i<=m;++i){
			while(j<=n&&a[j]<p[i].l)++j;
			lb[j-1]=min(lb[j-1],i);
			rb[j-1]=max(rb[j-1],i);
			fl[j-1]=1;
		}
		for(i=1;i<=n;++i)dp[i][0]=dp[i][1]=1e18;
		if(fl[0])dp[1][1]=a[1]-p[lb[0]].r,dp[1][0]=dp[1][1]*2ll;
		else dp[1][1]=dp[1][0]=0;
		for(i=1;i<n;++i)for(j=0;j<2;++j)for(k=0;k<2;++k){
			if(!fl[i])dp[i+1][k]=min(dp[i+1][k],dp[i][j]);
			else{
				dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(a[i+1]-p[lb[i]].r)*(k==0?2ll:1ll));
				for(int o=lb[i];o<rb[i];++o){
					dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(a[i+1]-p[o+1].r)*(k==0?2ll:1ll)+
					(p[o].l-a[i])*(j==1?2ll:1ll));
				}
				dp[i+1][k]=min(dp[i+1][k],dp[i][j]+(p[rb[i]].l-a[i])*(j==1?2ll:1ll));
			}
		}
		if(fl[n])dp[n][0]+=(p[rb[n]].l-a[n]),dp[n][1]+=(p[rb[n]].l-a[n])*2ll;
		cout<<min(dp[n][0],dp[n][1])<<'\n';
	}
	return 0;
}