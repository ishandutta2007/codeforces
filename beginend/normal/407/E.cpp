#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#define ls d<<1
#define rs d<<1|1

const int N=200005;

int n,k,d,lef[N],stack1[N],stack2[N],a[N],pos;
struct tree{int mn,tag;}t[N*4];
std::map<int,int> ma;

void pushdown(int d)
{
	int w=t[d].tag;t[d].tag=0;
	t[ls].tag+=w;t[ls].mn+=w;
	t[rs].tag+=w;t[rs].mn+=w;
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {t[d].tag+=z;t[d].mn+=z;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	t[d].mn=std::min(t[ls].mn,t[rs].mn);
}

void query(int d,int l,int r,int x,int y,int z)
{
	if (t[d].mn>z) return;
	if (l==r) {pos=l;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=l&&r<=y)
	{
		if (t[ls].mn<=z) query(ls,l,mid,x,y,z);
		else query(rs,mid+1,r,x,y,z);
		return;
	}
	if (x<=mid) query(ls,l,mid,x,y,z);
	if (!pos&&y>mid) query(rs,mid+1,r,x,y,z);
}

void solve()
{
	int len=1,R=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (i>1&&a[i]==a[i-1]) lef[i]=lef[i-1]+1;
		else lef[i]=1;
		if (lef[i]>len) len=lef[i],R=i;
	}
	printf("%d %d\n",R-len+1,R);
}

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	if (!d) {solve();return 0;}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);a[i]+=1e9; 
		if (i>1&&a[i]%d==a[i-1]%d) lef[i]=std::max(lef[i-1],ma[a[i]]+1);
		else lef[i]=i;
		ma[a[i]]=i;
	}
	for (int i=1;i<=n;i++) a[i]/=d;
	int top1=0,top2=0,len=1,R=1;
	for (int i=1;i<=n;i++)
	{
		ins(1,1,n,i,i,i);
		while (top1&&a[i]>=a[stack1[top1]]) ins(1,1,n,stack1[top1-1]+1,stack1[top1],a[i]-a[stack1[top1]]),top1--;
		while (top2&&a[i]<=a[stack2[top2]]) ins(1,1,n,stack2[top2-1]+1,stack2[top2],a[stack2[top2]]-a[i]),top2--;
		stack1[++top1]=stack2[++top2]=i;
		pos=0;
		query(1,1,n,lef[i],i,k+i);
		if (pos&&i-pos+1>len) len=i-pos+1,R=i;
	}
	printf("%d %d\n",R-len+1,R);
	return 0;
}