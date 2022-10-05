#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int dp[N],pd[N],f[N],n,a[N];
void get(int x){
	if(x>n)return;
	int u=dp[x],v=pd[x];
	dp[x]=0,pd[x]=n+1;
	if(a[x]>a[x-1]){
		dp[x]=dp[x-1];
		if(dp[x-1]>a[x])pd[x]=a[x-1];
		if(pd[x-1]<a[x])dp[x]=max(dp[x],a[x-1]);
	}else{
		pd[x]=pd[x-1];
		if(pd[x-1]<a[x])dp[x]=a[x-1];
		if(dp[x-1]>a[x])pd[x]=min(pd[x],a[x-1]);
	}
	if(dp[x]==u&&pd[x]==v)return;
	if(dp[x]==0&&pd[x]==n+1){f[x]=0;return;}
	get(x+1),f[x]=1+f[x+1];
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	long long ans=0;
	int i;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=n;i;--i)dp[i]=n+1,pd[i]=0,get(i+1),f[i]=f[i+1]+1,ans+=f[i];
	cout<<ans;
}