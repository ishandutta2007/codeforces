#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int l,r,wz;
	bool operator<(const apple &other)const
	{
		if(l!=other.l)return l<other.l;
		if(r!=other.r)return r<other.r;
		return wz<other.wz;
	}
	apple(int l=0,int r=0,int wz=0):l(l),r(r),wz(wz){}
}p1[1000005];
struct applee
{
	int l,r,wz;
	bool operator<(const applee &other)const
	{
		if(r!=other.r)return r<other.r;
		if(l!=other.l)return l<other.l;
		return wz<other.wz;
	}
	applee(int l=0,int r=0,int wz=0):l(l),r(r),wz(wz){}
}p2[1000005];
int n,k;
int c[1000005],q[1000005],l[1000005],r[1000005];
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int z=x;
	x=y,y=z-a/b*y;
}
int niyuan(int a)
{
	int x,y;
	exgcd(a,998244353,x,y);
	return (x%998244353+998244353)%998244353;
}
int print()
{
	c[k-1]=1;
	for(int i=k;i<=1000000;i++)
	{
		c[i]=1ll*i*niyuan(i-k+1)%998244353;
		c[i]=1ll*c[i-1]*c[i]%998244353;
	}
}
int C(int n,int k)
{
	int a1=1,a2=1,a3=1;
	for(int i=1;i<=n;i++)a1=1ll*a1*i%998244353;
	for(int i=1;i<=k;i++)a2=1ll*a2*i%998244353;
	for(int i=1;i<=n-k;i++)a3=1ll*a3*i%998244353;
	int ans=1ll*niyuan(a2)*niyuan(a3)%998244353;
	return 1ll*ans*a1%998244353;
}
int main()
{
	cin>>n>>k;
	int ans=C(n,k),tot=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]),q[++tot]=l[i],q[++tot]=r[i];
	print();
	sort(q+1,q+tot+1);
	tot=unique(q+1,q+tot+1)-q-1;
	for(int i=1;i<=n;i++)
	{
		p1[i].l=p2[i].l=lower_bound(q+1,q+tot+1,l[i])-q;
		p1[i].r=p2[i].r=lower_bound(q+1,q+tot+1,r[i])-q;
		p1[i].wz=p2[i].wz=i;
	}
	sort(p1+1,p1+n+1);
	sort(p2+1,p2+n+1);
	for(int i=1;i<=n;i++)
	{
		apple s=p1[i];
		int ll=s.l,rr=s.r,ww=s.wz;
		int df=lower_bound(p1+1,p1+n+1,apple(rr+1,0,0))-p1;
		int b=n-df+1;
		df=lower_bound(p2+1,p2+n+1,applee(ll,rr,ww))-p2+1;
		int a=n-df+1;
		ans-=c[a];
		if(a>=b)ans+=c[a-b];
		ans=(ans%998244353+998244353)%998244353;
	}
	cout<<ans<<endl;
	return 0;
}