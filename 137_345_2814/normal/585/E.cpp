#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10000007
#define mod 1000000007
int ch[N],pr[N/10],ct,n,su[N],pw[N],cnt[N],a,s3[N],as,f[N];
vector<int> s;
void dfs(int l,int d,int t)
{
	if(l==s.size()){
	if(d>1)as=(as+1ll*t*su[d])%mod;return;
	}
	dfs(l+1,d*s[l],mod-t);
	dfs(l+1,d,t);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a),su[a]++,s3[a]++;
	for(int i=2;i<=1e7;i++)
	{
		if(!ch[i])pr[++ct]=i,f[i]=i;
		for(int j=1;1ll*i*pr[j]<=1e7&&j<=ct;j++)
		{
			ch[i*pr[j]]=1;f[i*pr[j]]=min(f[i],pr[j]);
			if(!i%pr[j])break;
		}
	}
	for(int i=1;i<=1e7;i++)
	for(int j=i*2;j<=1e7;j+=i)
	su[i]+=su[j];
	pw[0]=1;for(int i=1;i<=1e7;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=1e7;i++)su[i]=pw[su[i]]-1;
	for(int i=1e7;i>=1;i--)
	for(int j=i*2;j<=1e7;j+=i)
	su[i]=(su[i]-su[j]+mod)%mod;
	as=1;for(int i=1;i<=n;i++)as=as*2%mod;as--;
	as=1ll*(as-su[1]+mod)%mod*n%mod;
	for(int i=1;i<=1e7;i++)
	for(int j=i*2;j<=1e7;j+=i)
	su[i]=(su[i]+su[j])%mod;
	for(int i=1;i<=1e7;i++)
	if(s3[i])
	{
		s.clear();
		int tp=i;
		while(tp>1)
		{
			int e=f[tp];
			s.push_back(e);
			while(tp%e==0)tp/=e;
		}
		dfs(0,1,s3[i]);
	}
	printf("%d\n",as);
}