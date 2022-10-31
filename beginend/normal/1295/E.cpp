#include<bits/stdc++.h>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=200005;
const LL inf=(LL)1e18;

int n,p[N],a[N];
struct tree{LL mn,tag;}t[N*4];

void mark(int d,LL w)
{
	t[d].mn+=w;t[d].tag+=w;
}

void pushdown(int d)
{
	if (!t[d].tag) return;
	LL w=t[d].tag;t[d].tag=0;
	mark(ls,w);mark(rs,w);
}

void ins(int d,int l,int r,int x,int y,LL z)
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
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) ins(1,0,n,p[i],n,a[i]);
	LL ans=inf;
	for (int i=1;i<n;i++)
	{
		ins(1,0,n,p[i],n,-a[i]);
		ins(1,0,n,0,p[i]-1,a[i]);
		ans=std::min(ans,t[1].mn);
	}
	printf("%lld\n",ans);
	return 0;
}