#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define mp std::make_pair
#define pb push_back

typedef std::pair<int,int> pi;

const int N=100005;

int n,m,c[N],ans[N],sum[N];
struct pts{int x,y;}p[N*3];
struct data{int l,r,id;}q[N];
std::vector<int> ls[N];
std::map<pi,int> ma;

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

pi get_k(pts a,pts b)
{
	int x=a.x-b.x,y=a.y-b.y,d=gcd(abs(x),abs(y));
	return mp(x/d,y/d);
}

bool cmp(data a,data b)
{
	return a.r<b.r;
}

void ins(int x)
{
	while (x<=n+1) c[x]++,x+=x&(-x);
}

int query(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int tot;scanf("%d",&tot);
		pi k;
		for (int j=1;j<=tot;j++) scanf("%d%d",&p[j].x,&p[j].y);
		for (int j=1;j<tot;j++) k=get_k(p[j],p[j+1]),ls[i].pb(ma[k]),ma[k]=i;
		k=get_k(p[tot],p[1]);ls[i].pb(ma[k]);ma[k]=i;
		sum[i]=sum[i-1]+tot;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	std::sort(q+1,q+m+1,cmp);
	int now=1;
	for (int i=1;i<=m;i++)
	{
		while (now<=q[i].r)
		{
			for (int j=0;j<ls[now].size();j++) ins(ls[now][j]+1);
			now++;
		}
		ans[q[i].id]=sum[q[i].r]-query(q[i].r+1)+query(q[i].l)-sum[q[i].l-1];
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}