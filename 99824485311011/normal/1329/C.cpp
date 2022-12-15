#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int T,h,g,a[1<<21],siz[1<<21];
ll sum=0;
vector<int> opt;
bool del(int p,int dep)
{
	if(!a[lc]&&!a[rc])
	{
		if(dep>0)return 0;
		a[p]=0;
		siz[p]=0;
		return 1;
	}
	if(a[lc]>a[rc])
	{
		int t=a[lc];
//		a[p]=a[lc];
		bool c=del(lc,dep-1);
//		siz[p]--;
		if(!c)return 0;
		a[p]=t;
		siz[p]=siz[lc]+siz[rc]+1;
		return 1;
	}
	else
	{
		int t=a[rc];
//		a[p]=a[rc];
		bool c=del(rc,dep-1);
		if(!c)return 0;
		a[p]=t;
//		siz[p]--;
		siz[p]=siz[lc]+siz[rc]+1;
		return 1;
	}
}
void calc(int p,int dep,int dep2)
{
//	if(!dep)return;
	while(a[p])
	{
		int v=a[p];
		if(del(p,dep2))
		{
			opt.push_back(p);
			sum-=v;
		}
		else break;
	}
	if(!a[p])return;
//	if(dep2==0)
//	{
//		while(a[p])opt.push_back(p),sum-=a[p],del(p);
//		return;
//	}
//	while(1)
//	{
//		if(a[lc]>a[rc])
//		{
//			if(siz[lc]<=((1<<(dep2-1))-1))break;
//		}
//		else
//		{
//			if(siz[rc]<=((1<<(dep2-1))-1))break;
//		}
//		sum-=a[p];
//		opt.push_back(p);
//		del(p);
//	}
//	while(siz[lc]>((1<<(dep2-1))-1)&&siz[rc]>((1<<(dep2-1))-1))opt.push_back(p),sum-=a[p],del(p);
//	if(siz[lc]>((1<<(dep2-1))-1))calc(lc,dep-1,dep2-1);
//	else if(siz[rc]>((1<<(dep2-1))-1))calc(rc,dep-1,dep2-1);
	calc(lc,dep-1,dep2-1);
	calc(rc,dep-1,dep2-1);
}
void solve()
{
	scanf("%d%d",&h,&g);
	sum=0;
	fill(a+1,a+(1<<(h+1)),0);
	for(int i=1;i<(1<<h);i++)scanf("%d",&a[i]),sum+=a[i];
	fill(siz+1,siz+(1<<(h+1)),0);
	for(int p=(1<<h)-1;p>=1;p--)siz[p]=siz[lc]+siz[rc]+1;
	opt.clear();
	calc(1,h,g);
	printf("%lld\n",sum);
//	printf("%d\n",opt.size());
//	printf("%d\n",siz[1]);
//	for(int i=0;i<(1<<h);i++)printf("%d ",a[i]);
//	puts("");
	for(auto &x:opt)printf("%d ",x);
	puts("");
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}