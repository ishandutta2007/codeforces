#include<bits/stdc++.h>
#define pb push_back

const int N=300005;

int n,m,a[N],c[N],tot,rt[N],sz,rig[N];
std::vector<int> vec[N];
struct tree{int l,r,s;}t[N*30];
struct data{int l,r,op,id,c,x,y;}q[N*10];

void ins(int &d,int l,int r,int x)
{
	int p=d;d=++sz;t[d]=t[p];
	if (l==r) {t[d].s=1;return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
	t[d].s=t[t[d].l].s+t[t[d].r].s;
}

int query(int d,int l,int r,int x,int y)
{
	if (x>y) return 0;
	if (x<=l&&r<=y) return t[d].s;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return query(t[d].l,l,mid,x,y)+query(t[d].r,mid+1,r,x,y);
}

bool cmp(data a,data b)
{
	return a.x<b.x||a.x==b.x&&a.op<b.op;
}

void ins(int x,int y)
{
	while (x<=m) c[x]+=y,x+=x&(-x);
}

int query(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]),vec[a[i]].pb(i);
	for (int i=1;i<=n;i++)
	{
		int ls=0;
		for (auto pos:vec[i])
		{
			int l1=ls+1,l2=pos,r1=pos,r2=m;
			tot++;q[tot].op=1;q[tot].l=r1;q[tot].r=r2;q[tot].c=1;q[tot].x=l1;
			tot++;q[tot].op=1;q[tot].l=r1;q[tot].r=r2;q[tot].c=-1;q[tot].x=l2+1;
			ls=pos;
		}
	}
	for (int i=1;i<=m;i++) rt[i]=rt[i-1],ins(rt[i],1,n,a[i]);
	for (int i=1;i<=n;i++)
	{
		int pos=(vec[i].size()?vec[i][0]:m);
		rig[i]=i+query(rt[pos],1,n,i+1,n);
		pos=0;
		for (auto k:vec[i])
		{
			if (pos&&pos+1<k) tot++,q[tot].op=2,q[tot].x=pos+1,q[tot].y=k-1,q[tot].id=i;
			pos=k;
		}
		if (pos&&pos<m) tot++,q[tot].op=2,q[tot].x=pos+1,q[tot].y=m,q[tot].id=i;
	}
	std::sort(q+1,q+tot+1,cmp);
	for (int i=1;i<=tot;i++)
		if (q[i].op==1) ins(q[i].l,q[i].c),ins(q[i].r+1,-q[i].c);
		else rig[q[i].id]=std::max(rig[q[i].id],query(q[i].y)+1);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",vec[i].size()?1:i,rig[i]);
	return 0;
}