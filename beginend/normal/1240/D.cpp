#include<bits/stdc++.h>

typedef long long LL;

const int N=300005;

int n,sz,a[N],dep[N],fa[N],rt[N];
struct tree{int l,r,pos;}t[N*30];

void ins(int &d,int l,int r,int x,int y)
{
	int p=d;d=++sz;t[d]=t[p];
	if (l==r) {t[d].pos=y;return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x,y);
	else ins(t[d].r,mid+1,r,x,y);
}

int query(int d,int l,int r,int x)
{
	if (l==r) return t[d].pos;
	int mid=(l+r)/2;
	if (x<=mid) return query(t[d].l,l,mid,x);
	else return query(t[d].r,mid+1,r,x);
}

void clear()
{
	sz=0;
	for (int i=0;i<=n;i++) dep[i]=fa[i]=rt[i]=0;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		clear();
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		LL ans=0;
		for (int i=1;i<=n;i++)
		{
			fa[i]=query(rt[i-1],1,n,a[i]);
			if (fa[i]) dep[i]=dep[fa[i]-1]+1;
			else dep[i]=0;
			fa[i]--;
			rt[i]=rt[fa[i]];
			ins(rt[i],1,n,a[i],i);
			ans+=dep[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}