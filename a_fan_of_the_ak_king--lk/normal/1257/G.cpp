#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=998244353;
int n,p,a[3000005],b[300005],m;
int r[1000005],siz[1000005],mx,i;
long long tmpa[1000005],tmpb[1000005],ans[1000005];
ll qpow(ll a,ll b)
{
	ll s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
void NTT(ll *f,int limit,int op)
{
	for(ri i=0;i<limit;++i)
		r[i]=(r[i>>1]>>1)|((i&1)?limit>>1:0);
	for(ri i=0;i<limit;++i)
		if(i<r[i])
			swap(f[i],f[r[i]]);
	for(ri i=2;i<=limit;i<<=1)
	{
		ll wn=qpow(3,(M-1)/i*op+(M-1)*(op==-1));
		for(ri j=0;j<limit;j+=i)
		{
			ll s=1;
			for(ri k=j;k<j+(i>>1);++k)
			{
				ll a=f[k],b=f[k+(i>>1)]*s;
				f[k]=(a+b)%M;
				f[k+(i>>1)]=(a-b)%M;
				s=s*wn%M;
			}
		}
	}
	if(op==-1)
	{
		ll s=qpow(limit,M-2);
		for(ri i=0;i<limit;++i)
			f[i]=f[i]*s%M;
	}
}
void dfs2(int x,int l,int r)
{
	if(l==r)
	{
		siz[x]=b[l];
		return;
	}
	int mid=l+r>>1;
	dfs2(x<<1,l,mid);
	dfs2(x<<1|1,mid+1,r);
	siz[x]=siz[x<<1]+siz[x<<1|1];
}
int dfs(int x,int l,int r)
{
	int i;
	if(l==r)
	{
		for(i=0;i<=b[l];++i)
			ans[i]=1;
		return siz[x];
	}
	int mid=l+r>>1;
	long long tmpa[siz[x]*4],tmpb[siz[x]*4];
	memset(tmpa,0,sizeof(tmpa));
	memset(tmpb,0,sizeof(tmpb));
	int a=dfs(x<<1,l,mid);
	for(i=0;i<=a;++i)
		tmpa[i]=ans[i];
	int b=dfs(x<<1|1,mid+1,r);
	for(i=0;i<=b;++i)
		tmpb[i]=ans[i];
	int lim=1;
	while(lim<=siz[x])
		lim<<=1;
	NTT(tmpa,lim,1);
	NTT(tmpb,lim,1);
	for(i=0;i<lim;++i)
		tmpa[i]=tmpa[i]*tmpb[i]%M;
	NTT(tmpa,lim,-1);
	for(i=0;i<=siz[x];++i)
		ans[i]=tmpa[i];
	/*cout<<l<<' '<<r<<endl;
	for(i=0;i<=siz[x];++i)
		cout<<ans[i]<<' ';
	cout<<endl;*/
	return siz[x];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p);
		++a[p];
		mx=max(mx,a[p]);
	}
	for(i=1;i<=3000000;++i)
		if(a[i])
			b[++m]=a[i];
	dfs2(1,1,m);
	dfs(1,1,m);
	cout<<(ans[n/2]%M+M)%M<<endl;
}