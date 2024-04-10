#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;
const LL inf=1000000000;

int n,m,w[N],tot,a[105],nx[N];
bool flag;

int ksm(int x,int y,int mo)
{
	int ans=1;bool f1=0;
	while (y)
	{
		if (y&1)
		{
			flag|=((LL)ans*x>inf)|f1;
			if (flag) ans=(LL)ans*x%mo;
			else ans*=x;
		}
		f1|=((LL)x*x>inf);
		if (f1||flag) x=(LL)x*x%mo;
		else x*=x;
		y>>=1;
	}
	return ans;
}

int get_phi(int n)
{
	int ans=n;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
		{
			ans=ans/i*(i-1);
			while (n%i==0) n/=i;
		}
	if (n>1) ans=ans/n*(n-1);
	return ans;
}

int solve(int d,int l,int r)
{
	int mo=a[d];
	if (l==r)
	{
		if (w[l]>inf) {flag=1;return w[l]%mo;}
		else return w[l];
	}
	if (d==tot&&r-l+1>10) {flag=1;return 0;}
	int phi=a[d+1],x=solve(min(tot,d+1),l+1,r);
	if (flag) x+=phi;
	else if (x>=phi) x=x%phi+phi;
	return ksm(w[l],x,mo);
}

int main()
{
	scanf("%d%d",&n,&m);
	a[0]=m;
	while (a[tot]>1) tot++,a[tot]=get_phi(a[tot-1]);
	a[tot+1]=1;
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	int q;scanf("%d",&q);
	nx[n+1]=n+1;
	for (int i=n;i>=1;i--) nx[i]=(w[i]==1)?i:nx[i+1];
	while (q--)
	{
		int l,r;scanf("%d%d",&l,&r);
		int tmp=nx[l];
		if (tmp<=r) r=tmp-1;
		if (l>r) puts(m>1?"1":"0");
		else flag=0,printf("%d\n",solve(0,l,r)%m);
	}
	return 0;
}