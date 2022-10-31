#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1

const int N=300005;

int n,a[N],b[N],pos[N],ans[N];
struct tree{int mn,tag;}t[N*4];

void mark(int d,int w)
{
	t[d].tag+=w;t[d].mn+=w;
}

void pushdown(int d)
{
	mark(ls,t[d].tag);
	mark(rs,t[d].tag);
	t[d].tag=0;
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {mark(d,z);return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	t[d].mn=std::min(t[ls].mn,t[rs].mn);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	int now=n;
	ins(1,1,n,1,pos[n],-1);
	ans[0]=n;
	for (int i=1;i<n;i++)
	{
		ins(1,1,n,1,b[i],1);
		while (t[1].mn>=0) now--,ins(1,1,n,1,pos[now],-1);
		ans[i]=now;
	}
	for (int i=0;i<n;i++) printf("%d ",ans[i]);
	return 0;
}