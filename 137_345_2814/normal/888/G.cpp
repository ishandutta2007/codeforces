#include<cstdio>
using namespace std;
int s[3000004][2],sz[3000004],n,v,cnt=1;
long long ans,ans2=1,mod=1000000007;
void insert(int dep,int s1,int m)
{
	sz[m]++;
	if(dep<0)return;
	int tmp=(s1>>dep)&1;
	if(!s[m][tmp])
	s[m][tmp]=++cnt;
	if(tmp)
	s1^=1<<dep;
	insert(dep-1,s1,s[m][tmp]);
}
int pw(int a,int p)
{
	int ans=1;
	while(p)
	{
		if(p&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		p>>=1;
	}
	return ans;
}
int cnt2;
int que(int s1,int m,int dep)
{
	if(dep==-1)return s1;
	int s2=s1>>dep&1;
	if(s1&(1<<dep))
	s1^=1<<dep;
	if(s[m][s2])
	return que(s1,s[m][s2],dep-1);
	else
	return que(s1|(1<<dep),s[m][!s2],dep-1);
}
int mx;
void dfs2(int s1,int m,int dep,int a,int b)
{
	if(!m)
	return;
	if(dep==-1)
	{
		int sb=que(s1,a,b);
		if(sb<mx)mx=sb;
	}
	dfs2(s1,s[m][0],dep-1,a,b);
	dfs2(s1|(1<<dep),s[m][1],dep-1,a,b);
}
void dfs(int m,int dep)
{
	if(dep<0)return;
	if(!m)return;
	if(s[m][0]&&s[m][1])
	{
		mx=1e9;
		if(sz[s[m][0]]>sz[s[m][1]])
		dfs2(0,s[m][1],dep-1,s[m][0],dep-1);
		else dfs2(0,s[m][0],dep-1,s[m][1],dep-1);
		ans+=(1<<dep)+mx;
	}
	dfs(s[m][0],dep-1);dfs(s[m][1],dep-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&v),insert(30,v,1);
	dfs(1,30);
	printf("%lld\n",ans);
}