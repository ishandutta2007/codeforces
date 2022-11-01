#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long LL;

const int N=500005;
const LL inf=(LL)1e16;

int n,a[N],b[N],sz,p[N],m,pos[N],rt[N];
LL f[N];
vector<int> vec[N];
struct tree{int l,r;LL s;}t[N*20];

void ins(int &d,int l,int r,int x,int w)
{
	int p=d;d=++sz;t[d]=t[p];
	t[d].s+=w;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x,w);
	else ins(t[d].r,mid+1,r,x,w);
}

LL query(int d,int p,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return t[d].s-t[p].s;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,t[p].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,t[p].r,mid+1,r,x,y);
	else return query(t[d].l,t[p].l,l,mid,x,y)+query(t[d].r,t[p].r,mid+1,r,x,y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]),p[i]=-p[i];
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
	{
		pos[i]=lower_bound(b+1,b+m+1,a[i])-b;
		if (b[pos[i]]==a[i]) vec[pos[i]].pb(i);
		rt[i]=rt[i-1];
		if (p[i]<0) ins(rt[i],1,n,a[i],p[i]);
	}
	for (int i=1;i<=n;i++) f[i]=inf;
	for (int k:vec[1]) f[k]=p[k];
	for (int i=2;i<=m;i++)
	{
		vector<int> c;
		int p1=0,p2=0;
		while (p1<vec[i-1].size()||p2<vec[i].size())
			if (p1<vec[i-1].size()&&(p2==vec[i].size()||vec[i][p2]>vec[i-1][p1])) c.pb(vec[i-1][p1++]);
			else c.pb(vec[i][p2++]);
		LL mn=inf;
		for (int j=0;j<c.size();j++)
		{
			if (j&&mn<inf) mn+=query(rt[c[j]],rt[c[j-1]],1,n,1,b[i-1]);
			if (pos[c[j]]==i-1) mn=min(f[c[j]],mn);
			else if (mn<inf) f[c[j]]=min(f[c[j]],mn+p[c[j]]);
		}
	}
	LL ans=inf;
	for (int k:vec[m])
		if (f[k]<inf) ans=min(ans,f[k]+query(rt[n],rt[k],1,n,1,b[m]));
	if (ans==inf) puts("NO");
	else
	{
		puts("YES");
		for (int i=1;i<=n;i++) ans-=p[i];
		printf("%lld\n",ans);
	}
	return 0;
}