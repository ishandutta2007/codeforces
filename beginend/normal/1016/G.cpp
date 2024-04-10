#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

typedef long long LL;

const int N=200005;

int n,bin[20],f[1000005],po[20],ppo[N][20];
LL a[N],X,Y,tot,pri[20];

LL gcd(LL x,LL y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void add(LL p)
{
	int s1=0,s2=0;LL t1=X,t2=Y;
	while (t1%p==0) t1/=p,s1++;
	while (t2%p==0) t2/=p,s2++;
	if (s1<s2) pri[++tot]=p;
}

void divi(LL r)
{
	for (LL i=2;i<=1000000;i++)
		if (r%i==0)
		{
			add(i);
			while (r%i==0) r/=i;
		}
	if (r==1) return;
	LL w=sqrt(r);
	if (w*w==r) add(w);
	else
	{
		a[0]=X;
		for (int i=0;i<=n;i++)
		{
			w=gcd(a[i],r);
			if (w>1&&w<r) {add(w);add(r/w);return;}
		}
		add(r);
	}
}

int main()
{
	scanf("%d%lld%lld",&n,&X,&Y);
	if (Y%X!=0) {puts("0");return 0;}
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	divi(Y);
	bin[0]=1;
	for (int i=1;i<=tot;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=tot;i++)
	{
		LL tmp=X;po[i]=0;
		while (tmp%pri[i]==0) tmp/=pri[i],po[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		int mask=0;LL tmp=a[i];
		for (int j=1;j<=tot;j++)
		{
			while (tmp%pri[j]==0) tmp/=pri[j],ppo[i][j]++;
			if (ppo[i][j]>po[j]) mask+=bin[j-1];
		}
		if (a[i]%X==0) f[mask]++;
	}
	for (int j=0;j<tot;j++)
		for (int i=0;i<bin[tot];i++)
			if (i&bin[j]) f[i]+=f[i-bin[j]];
	LL ans=0;
	for (int i=1;i<=tot;i++)
	{
		LL tmp=Y;po[i]=0;
		while (tmp%pri[i]==0) tmp/=pri[i],po[i]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (Y%a[i]!=0) continue;
		int mask=0;
		for (int j=1;j<=tot;j++) if (ppo[i][j]<po[j]) mask+=bin[j-1];
		ans+=f[mask^(bin[tot]-1)];
	}
	printf("%lld\n",ans);
	return 0;
}