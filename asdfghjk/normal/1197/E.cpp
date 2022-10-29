#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005,md=1000000007;
struct node
{
	int l,r;
}a[N];
struct mode
{
	int ch[2],size,r,val,mn,f,fl;
}b[N];
int n,i,j,root,f[N],dp[N],mn=1<<30,ans,mxl;
inline void Read(int &x)
{
	char c;
	while((c=getchar())<'0'||c>'9');
	x=c-'0';
	while((c=getchar())>='0'&&c<='9')
		x=x*10+c-'0';
}
bool Cmp(node a,node b)
{
	return a.r<b.r;
}
int rk(int o,int x)
{
	if(!o)
		return 0;
	if(x>=b[o].r)
		return b[b[o].ch[0]].size+1+rk(b[o].ch[1],x);
	return rk(b[o].ch[0],x);
}
void maintain(int o)
{
	b[o].size=b[b[o].ch[0]].size+b[b[o].ch[1]].size+1;
	b[o].mn=min(b[o].val,min(b[b[o].ch[0]].mn,b[b[o].ch[1]].mn));
	b[o].fl=0;
	if(b[o].mn==b[o].val)
		b[o].fl=b[o].f;
	if(b[o].mn==b[b[o].ch[0]].mn)
		b[o].fl=(b[o].fl+b[b[o].ch[0]].fl)%md;
	if(b[o].mn==b[b[o].ch[1]].mn)
		b[o].fl=(b[o].fl+b[b[o].ch[1]].fl)%md;
}
int cmp(int o,int x)
{
	if(b[b[o].ch[0]].size+1==x)
		return -1;
	return b[b[o].ch[0]].size+1<x;
}
void rotate(int &o,int d)
{
	int k=b[o].ch[d];
	b[o].ch[d]=b[k].ch[d^1];
	b[k].ch[d^1]=o;
	maintain(o);
	maintain(k);
	o=k;
}
void splay(int &o,int x)
{
	int k1=cmp(o,x);
	if(k1==-1)
		return;
	if(k1==1)
		x-=b[b[o].ch[0]].size+1;
	int k2=cmp(b[o].ch[k1],x);
	if(k2!=-1)
	{
		if(k2==1)
			x-=b[b[b[o].ch[k1]].ch[0]].size+1;
		splay(b[b[o].ch[k1]].ch[k2],x);
		if(k1==k2)
			rotate(o,k1);
		else
			rotate(b[o].ch[k1],k2);
	}
	rotate(o,k1);
}
int main()
{
	Read(n);
	for(i=1;i<=n;++i)
	{
		Read(a[i].r);
		Read(a[i].l);
		mxl=max(mxl,a[i].l);
	}
	sort(a+1,a+1+n,Cmp);
	b[0].mn=1<<30;
	b[root=1].size=b[1].f=b[1].fl=1;
	dp[0]=1;
	for(i=1;i<=n;++i)
	{
		j=rk(root,a[i].l);
		if(j==b[root].size)
			f[i]=b[root].mn+a[i].l,dp[i]=b[root].fl;
		else
		{
			splay(root,j+1);
			f[i]=b[b[root].ch[0]].mn+a[i].l;
			dp[i]=b[b[root].ch[0]].fl;
		}
		b[i+1].size=1,b[i+1].r=a[i].r,b[i+1].val=f[i]-a[i].r;
		b[i+1].mn=b[i+1].val;
		b[i+1].f=b[i+1].fl=dp[i];
		splay(root,b[root].size);
		b[root].ch[1]=i+1;
		maintain(root);
		if(a[i].r>mxl)
		mn=min(mn,f[i]);
		//printf("%d %d %d %d %d\n",a[i].l,a[i].r,f[i],dp[i],j);
	}
	for(i=1;i<=n;++i)
		if(f[i]==mn&&a[i].r>mxl)
			ans=(ans+dp[i])%md;
	printf("%d",ans);
	return 0;
}