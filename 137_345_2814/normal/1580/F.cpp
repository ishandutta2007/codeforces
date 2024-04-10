#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 132001
#define mod 998244353
int n,k,a,rev[N*2],g[2][N*2],ntt[N],v1[N],v2[N],fr[N],ifr[N],as[N],fg=255,inv[N],vl[N];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
void init(int d)
{
	fr[0]=1;for(int i=1;i<=1<<d;i++)fr[i]=1ll*fr[i-1]*i%mod;
	ifr[1<<d]=pw(fr[1<<d],mod-2);for(int i=(1<<d);i>=1;i--)ifr[i-1]=1ll*ifr[i]*i%mod,inv[i]=1ll*fr[i-1]*ifr[i]%mod;
	for(int i=2;i<=1<<d;i<<=1)for(int j=0;j<i;j++)rev[i+j]=(rev[i+(j>>1)]>>1)+(j&1?i>>1:0);
	for(int t=0;t<2;t++)
	for(int i=2;i<=1<<d;i<<=1)
	{
		int tp=pw(3,mod-1+(mod-1)*(t*2-1)/i);
		for(int j=0,vl=1;j<(i>>1);j++,vl=1ll*vl*tp%mod)g[t][i+j]=vl;
	}
}
void dft(int s,int *a,int t)
{
	for(int i=0;i<s;i++)ntt[rev[s+i]]=a[i];
	for(int l=2;l<=s;l<<=1)
	for(int i=0;i<s;i+=l)
	for(int j=i,st=l;j<i+(l>>1);j++,st++)
	{
		int v1=ntt[j],v2=1ll*ntt[j+(l>>1)]*g[t][st]%mod;
		ntt[j]=(v1+v2)%mod;ntt[j+(l>>1)]=(v1-v2+mod)%mod;
	}
	int tp=t?1:pw(s,mod-2);
	for(int i=0;i<s;i++)a[i]=1ll*ntt[i]*tp%mod;
}
vector<int> add(vector<int> a,vector<int> b)
{
	vector<int> c;
	int s1=a.size(),s2=b.size();
	for(int i=0;i<s1||i<s2;i++)c.push_back(((i<s1?a[i]:0)+(i<s2?b[i]:0))%mod);
	return c;
}
vector<int> mul(vector<int> a,vector<int> b,int n=1e7)
{
	vector<int> c;
	int s1=a.size(),s2=b.size();
	for(int i=0;i<s1+s2-1;i++)c.push_back(0);
	if(s1+s2<=fg)
	{
		for(int i=0;i<s1;i++)for(int j=0;j<s2;j++)c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
		while(c.size()>n)c.pop_back();
		return c;
	}
	int l=1;while(l<=s1+s2)l<<=1;
	for(int i=0;i<l;i++)v1[i]=v2[i]=0;
	for(int i=0;i<s1;i++)v1[i]=a[i];for(int i=0;i<s2;i++)v2[i]=b[i];
	dft(l,v1,1);dft(l,v2,1);for(int i=0;i<l;i++)v1[i]=1ll*v1[i]*v2[i]%mod;dft(l,v1,0);
	for(int i=0;i<s1+s2-1;i++)c[i]=v1[i];
	while(c.size()>n)c.pop_back();
	return c;
}
vector<int> polyinv(vector<int> a,int n)
{
	while(a.size()<n)a.push_back(0);
	vector<int> b;
	for(int i=0;i<n;i++)b.push_back(0);
	int tp=min(n,fg),st=pw(a[0],mod-2);
	for(int i=0;i<tp;i++)
	{
		int vl=i?0:1;
		for(int j=0;j<i;j++)vl=(vl-1ll*b[j]*a[i-j]%mod+mod)%mod;
		b[i]=1ll*vl*st%mod;
	}
	if(n<=fg)return b;
	int x=0;while((n>>x)>=fg*2-1)x++;
	while(1)
	{
		int l1=((n-1)>>x)+1,l2=(l1>>1)+1,l=1;
		while(l<=l1*2+4)l<<=1;
		for(int i=0;i<l;i++)v1[i]=v2[i]=0;
		for(int i=0;i<l1;i++)v1[i]=a[i];
		for(int i=0;i<l2;i++)v2[i]=b[i];
		dft(l,v1,1);dft(l,v2,1);for(int i=0;i<l;i++)v1[i]=1ll*v2[i]*(2-1ll*v1[i]*v2[i]%mod+mod)%mod;dft(l,v1,0);
		for(int i=0;i<l1;i++)b[i]=v1[i];
		if(!x)return b;x--;
	}
}
vector<int> polyln(vector<int> a,int n)
{
	vector<int> v1,v2=polyinv(a,n),as;
	for(int i=1;i<a.size()&&i<=n;i++)v1.push_back(1ll*a[i]*i%mod);
	v1=mul(v1,v2);
	as.push_back(0);
	for(int i=0;i<n;i++)as.push_back(1ll*v1[i]*inv[i+1]%mod);
	return as;
}
int main()
{
	init(17);
	scanf("%d%d",&n,&k);
	int m=k/2;
	vl[0]=1;
	for(int i=1;i<=n;i++)
	if(i&1)vl[i]=1ll*vl[i-1]*inv[i]%mod*(m-i/2)%mod;
	else vl[i]=1ll*vl[i-1]*inv[i]%mod*(m+i/2)%mod;
	vector<int> s1,s2;
	for(int i=0;i<=n;i++)s1.push_back(i&1?0:vl[i]);
	for(int i=0;i<=n;i++)s2.push_back(i&1?vl[i]:0);
	s2[0]=mod-1;
	vector<int> t1=mul(s2,polyinv(s1,n+1),n+1);
	for(int i=0;i<=n;i++)if((i+3)%4>1)t1[i]=(mod-t1[i])%mod;
	if(k&1)t1[1]=(t1[1]+1)%mod;
	for(int i=1;i<=n;i++)t1[i]=(i&1)*(mod-t1[i])%mod;
	vector<int> f1=polyln(t1,n+1);
	int as=1ll*n*(mod-f1[n])%mod;
	if(~n&1)
	{
		for(int i=2;i<=n;i++)if(i%4==2)s1[i]=(mod-s1[i])%mod;
		s1=polyln(s1,n+1);
		as=(as+1ll*n*(mod-s1[n])%mod)%mod;
	}
	printf("%d\n",as);
}