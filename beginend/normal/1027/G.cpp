#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>

typedef long long LL;

int n,tot,pri[9]={2,3,5,7,11,13,17,19,23},top;
LL m,x,a[50005],b[50005],f[50005],l[50005],prime[105];
std::map<LL,int> id;

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

LL mul(LL x,LL y,LL mo)
{
	x%=mo;y%=mo;
	LL ans=(x*y-(LL)((double)x*y/mo+0.1)*mo)%mo;
    ans+=ans<0?mo:0;
    return ans;
}

LL ksm(LL x,LL y,LL mo)
{
	LL ans=1;
	while (y)
	{
		if (y&1) ans=mul(ans,x,mo);
		x=mul(x,x,mo);y>>=1;
	}
	return ans;
}

bool MR(LL n)
{
	if (n==2) return 1;
	if (n%2==0) return 0;
	LL w=n-1;int lg=0;
	while (w%2==0) w/=2,lg++;
	for (int i=0;i<9;i++)
	{
		if (n==pri[i]) return 1;
		LL x=ksm(pri[i],w,n);
		for (int j=0;j<lg;j++)
		{
			LL y=mul(x,x,n);
			if (x!=1&&x!=n-1&&y==1) return 0;
			x=y;
		}
		if (x!=1) return 0;
	}
	return 1;
}

LL rho(LL n)
{
	LL c=rand()*rand()%(n-1)+1,x1=rand()*rand()%n,x2=x1,k=1,p=1;
	for (int i=1;p==1;i++)
	{
		x1=(mul(x1,x1,n)+c)%n;
		if (x1==x2) return 1;
		p=gcd(n,abs(x1-x2));
		if (i==k) k<<=1,x2=x1;
	}
	return p;
}

void divi(LL n)
{
	if (n==1) return;
	if (MR(n)) {b[++tot]=n;return;}
	LL p=1;
	while (p==1) p=rho(n);
	divi(p);divi(n/p);
}

void pre()
{
	for (LL i=1;i*i<=m;i++)
		if (m%i==0)
		{
			a[++n]=i;
			if (m/i!=i) a[++n]=m/i;
		}
	std::sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) id[a[i]]=i;
	LL tmp=m;
	for (LL i=2;i*i<=tmp;i++)
		if (tmp%i==0)
		{
			prime[++top]=i;
			while (tmp%i==0) tmp/=i;
		}
	if (tmp>1) prime[++top]=tmp;
}

int main()
{
	scanf("%lld%lld",&m,&x);
	pre();
	for (int i=1;i<=n;i++) f[i]=m/a[i]-1;
	for (int j=1;j<=top;j++)
		for (int i=1;i<=n;i++)
			if (a[i]%prime[j]==0) f[id[a[i]/prime[j]]]-=f[i];
	for (int i=n;i>=1;i--)
	{
		l[i]=a[i];
		for (int j=1;j<=top;j++)
			if (l[i]%prime[j]==0) l[i]=l[i]/prime[j]*(prime[j]-1);
		tot=0;divi(l[i]);
		std::sort(b+1,b+tot+1);
		tot=std::unique(b+1,b+tot+1)-b-1;
		for (int j=1;j<=tot;j++)
			while (l[i]%b[j]==0&&ksm(x,l[i]/b[j],a[i])==1) l[i]/=b[j];
	}
	LL ans=1;
	for (int i=1;i<n;i++)
	{
		int j;
		for (j=1;a[j]!=m/a[i];j++);
		ans+=f[i]/l[j];
	}
	printf("%lld\n",ans);
	return 0;
}