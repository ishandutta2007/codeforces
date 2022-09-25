//remake 
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000060
int n,q,v[N],a,b;
struct segt{
	struct node{int l,r,mn,su,lz;}e[N*4];
	void doit(int x,int k){e[x].mn+=k;e[x].lz+=k;}
	void pushdown(int x){if(e[x].lz)doit(x<<1,e[x].lz),doit(x<<1|1,e[x].lz);e[x].lz=0;}
	void pushup(int x)
	{
		e[x].mn=min(e[x<<1].mn,e[x<<1|1].mn);e[x].su=0;
		if(e[x].mn==e[x<<1].mn)e[x].su+=e[x<<1].su;
		if(e[x].mn==e[x<<1|1].mn)e[x].su+=e[x<<1|1].su;
	}
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;if(l==r)return;
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	}
	void modify1(int x,int s,int v)
	{
		if(e[x].l==e[x].r){e[x].su+=v;return;}
		pushdown(x);
		int mid=(e[x].l+e[x].r)>>1;
		modify1(x<<1|(mid<s),s,v);
		pushup(x);
	}
	void modify2(int x,int l,int r,int v)
	{
		if(e[x].l>=l&&e[x].r<=r){doit(x,v);return;}
		if(e[x].r<l||e[x].l>r)return;
		pushdown(x);
		modify2(x<<1,l,r,v);modify2(x<<1|1,l,r,v);
		pushup(x);
	}
}tr;
void modify(int x,int f)
{
	if(x>1&&v[x]>v[x-1])tr.modify2(1,v[x-1]+1,v[x],f);
	if(x<n&&v[x]<v[x+1])tr.modify2(1,v[x]+1,v[x+1],f);
	tr.modify1(1,v[x],f);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	tr.build(1,1,1e6);
	for(int i=1;i<=n;i++)
	{
		if(i<n&&v[i]<v[i+1])tr.modify2(1,v[i]+1,v[i+1],1);
		tr.modify1(1,v[i],1);
	}
	while(q--)
	{
		scanf("%d%d",&a,&b);
		modify(a,-1);v[a]=b;modify(a,1);
		printf("%d\n",tr.e[1].su);
	}
}