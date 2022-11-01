#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,k,a,b,rt,sz,bin[35];
LL f[N*30];
struct tree{int l,r,s;}t[N*30];

void ins(int &d,int l,int r,int x)
{
	if (!d) d=++sz;t[d].s++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

void calc(int d,int l,int r)
{
	if (!d) return;
	if (l==r) {f[d]=(!t[d].s?a:b*t[d].s);return;}
	if (!t[d].s) f[d]=a;
	else
	{
		int mid=(l+r)/2;
		calc(t[d].l,l,mid);
		calc(t[d].r,mid+1,r);
		f[d]=std::min(f[t[d].l]+f[t[d].r],(LL)(r-l+1)*b*t[d].s);
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&k,&a,&b);
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=k;i++)
	{
		int x;scanf("%d",&x);
		ins(rt,1,bin[n],x);
	}
	f[0]=a;
	calc(rt,1,bin[n]);
	printf("%lld\n",f[rt]);
	return 0;
}