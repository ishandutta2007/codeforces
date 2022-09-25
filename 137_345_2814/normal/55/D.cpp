#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll ch[61],cnt,dp[20][2520][61],d[21],mp[2532],ecnt;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm1(int a,int b){return b?a/gcd(a,b)*b:a;}
ll dfs(int dep,int mod,int lcm,int che)
{
	if(dep==cnt+1)
	return (mod%ch[lcm]==0);
	ll cnt1=0;
	if(!che&&dp[cnt-dep+1][mod][lcm]!=-1)
	return dp[cnt-dep+1][mod][lcm];
	if(che)
	{
		for(int i=0;i<=d[dep];i++)
		if(i<d[dep])
		cnt1+=dfs(dep+1,(mod*10+i)%2520,mp[lcm1(ch[lcm],i)],0);
		else
		cnt1+=dfs(dep+1,(mod*10+i)%2520,mp[lcm1(ch[lcm],i)],1);
		return cnt1;
	}
	else
	{
		for(int i=0;i<=9;i++)
		cnt1+=dfs(dep+1,(mod*10+i)%2520,mp[lcm1(ch[lcm],i)],0);
		return dp[cnt-dep+1][mod][lcm]=cnt1; 
	}
}
ll sol(ll x)
{	
	cnt=0;
	if(x==0)
	return 1;
	ll lsj=x;
	while(lsj)
	d[++cnt]=lsj%10,lsj/=10;
	for(int i=1;i<=cnt/2;i++)
	swap(d[i],d[cnt-i+1]);
	return dfs(1,0,48,1);
}
void dfs1(int i,int j)
{
	if(i>9)
	{
		if(!mp[j])
		{
			ch[++ecnt]=j;
			mp[j]=ecnt;
		}
		return;
	}
	dfs1(i+1,lcm1(j,i));
	dfs1(i+1,j);
}
int main()
{
	ll T,a,b;
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&T);
	dfs1(1,1);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",sol(b)-sol(a-1));
	}
}