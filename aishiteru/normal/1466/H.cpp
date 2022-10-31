#include<bits/stdc++.h>
using namespace std; 
const int N=105,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,i,j,a[N],vis[N],p[N],c[N],u[N],fi;
long long f[55555],fac[N],inv[N];
struct str{
	int a[45];
};
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
vector<str> g;
void Find(int i)
{
	int j;
	if(i>=41)
	{
		str e;
		memset(e.a,0,sizeof(e.a));
		for(j=1;j<=40;++j)
			e.a[j]=u[j];
		g.push_back(e);
		return;
	}
	for(j=0;j<=p[i]-c[i];++j)
	{
		u[i]=j;
		Find(i+1);
	}
}
long long C(int n,int m)
{
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
long long dfs(int i)
{
	if(f[i]!=-1)
		return f[i];
	if(i==fi)
		return 1;
	int j;
	int t=i,s=0;
	int cc[45];
	for(j=1;j<=40;++j)
	{
		c[j]=t%(p[j]+1);
		cc[j]=p[j]-c[j];
		t/=p[j]+1;
		s+=c[j]*j;
	}
	long long as=0;
	for(j=0;j<=s;++j)
		as=(as+C(s,j)*fac[j]%M*fac[n-j-1])%M;
	//cout<<'#'<<i<<' '<<s<<' '<<as<<endl;
	g.clear();
	Find(1);
	vector<str> w=g;
	//cout<<i<<endl;
	//for(auto it:g)
	//	cout<<it.a[1]<<' '<<it.a[2]<<endl;
	long long ans=0;
	for(auto it:w)
	{
		int su=0,e=-1,s=0;
		long long fa=1;
		for(j=1;j<=40;++j)
		{
			su+=it.a[j]*j;
			fa=fa*C(cc[j],it.a[j]);
			if(it.a[j]&1)
				e=-e;
		}
		for(j=40;j>=1;--j)
			s=s*(p[j]+1)+it.a[j];
		fa%=M;
		if(s)
			ans+=fa*qpow(as,su)%M*dfs(i+s)*e%M;
	}
	//cout<<i<<' '<<ans<<endl;
	return f[i]=ans%M;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
		if(!vis[i])
		{
			int s=0;
			for(j=i;!vis[j];j=a[j])
			{
				vis[j]=1;
				++s;
			}
			++p[s];
		}
	fac[0]=1;
	for(i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%M;
	for(i=0;i<=n;++i)
		inv[i]=qpow(fac[i],M-2);
	memset(f,-1,sizeof(f));
	for(i=40;i>=1;--i)
		fi=fi*(p[i]+1)+p[i];
	cout<<(dfs(0)%M+M)%M;
}