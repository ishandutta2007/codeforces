#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5][20],bit[20];
ll dfs(ll pos,ll lim,ll cnt)
{
	if(pos==0)return 1;
	if(!lim&&dp[cnt][pos]!=-1)return dp[cnt][pos];
	ll up=lim?bit[pos]:9,ans=0;
	for(int i=0;i<=up;i++){
		if(i==0)ans+=dfs(pos-1,lim&&(i==bit[pos]),cnt);
		else if(cnt<3)ans+=dfs(pos-1,lim&&(i==bit[pos]),cnt+1);
	}
	if(!lim)dp[cnt][pos]=ans;
	return ans;
}
ll query(ll x)
{
	int cnt=0;
	while(x)bit[++cnt]=x%10,x/=10;
	return dfs(cnt,1,0);
}
ll t,l,r;
int main()
{
	memset(dp,-1,sizeof(dp)),cin>>t;
	for(int i=1;i<=t;i++)
		cin>>l>>r,cout<<query(r)-query(l-1)<<endl;
	return 0;
}