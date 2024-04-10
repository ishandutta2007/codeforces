#include<cstdio>
using namespace std;
#define N 200050
long long n,s[N],tr[N],tr2[N],tr3[N],cnt,fr[N],mod=998244353;
inline int pw(int a,long long p){int ans=1;if(p<1)return 1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
void add(int x,int k){for(int i=x;i<=n;i+=i&-i)tr[i]+=k;}
int que(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=tr[i];return ans;}
void add2(int x,int k){for(int i=x;i<=n;i+=i&-i)tr2[i]+=k;}
int que2(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=tr2[i];return ans;}
void add3(int x,int k){for(int i=x;i<=n;i+=i&-i)tr3[i]+=k;}
int que3(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=tr3[i];return ans;}
int main()
{
	long long cnt100=0;
	scanf("%lld",&n);fr[0]=1;
	for(int i=1;i<=n;i++)add(i,1),add2(i,1),fr[i]=fr[i-1]*i%mod;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		if(s[i]==-1)
		cnt++;
		else
		add(i,-1),add2(s[i],-1),cnt100+=que3(n)-que3(s[i]),add3(s[i],1);
	}
	long long as=0;
	for(int i=1;i<=n;i++)
	if(s[i]!=-1)
	{
		long long tmp1=que(i),tmp2=que(n)-que(i),tmp3=que2(s[i]),tmp4=que2(n)-que2(s[i]);
		as=(as+tmp3*tmp2%mod*fr[cnt-1]+tmp1*tmp4%mod*fr[cnt-1])%mod;
	}
	as=(as+cnt*(cnt-1)%mod*fr[cnt]%mod*pw(4,mod-2))%mod;
	as=(as*pw(fr[cnt],mod-2))%mod;
	printf("%lld\n",(as+cnt100)%mod);
}