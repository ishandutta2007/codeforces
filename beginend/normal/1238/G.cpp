#include<bits/stdc++.h>
#define mp std::make_pair
#define ls d<<1
#define rs d<<1|1

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=500005;

int n,m,c,c0,ret[N],w[N],cap[N];
struct data{int t,x,y;}a[N];
std::priority_queue<pi> que;
struct tree{int mn,tag;}t[N*4];

bool cmp(data a,data b)
{
	return a.t<b.t;
}

void updata(int d)
{
	t[d].mn=std::min(t[ls].mn,t[rs].mn);
}

void pushdown(int d)
{
	int w=t[d].tag;t[d].tag=0;
	t[ls].tag+=w;t[ls].mn+=w;
	t[rs].tag+=w;t[rs].mn+=w;
}

void build(int d,int l,int r)
{
	t[d].tag=0;
	if (l==r) {t[d].mn=cap[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) {t[d].mn+=w;t[d].tag+=w;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,w);
	if (y>mid) ins(rs,mid+1,r,x,y,w);
	updata(d);
}

int query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return t[d].mn;
	pushdown(d);
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return std::min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&c0);
		int tot=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
			w[++tot]=a[i].t;
		}
		w[++tot]=m-1;w[++tot]=0;
		std::sort(w+1,w+tot+1);
		tot=std::unique(w+1,w+tot+1)-w-1;
		for (int i=1;i<=n;i++) a[i].t=std::lower_bound(w+1,w+tot+1,a[i].t)-w;
		ret[0]=c0;
		for (int i=1;i<tot;i++) ret[i]=ret[i-1]-(w[i+1]-w[i]);
		ret[tot]=ret[tot-1]-1;
		std::sort(a+1,a+n+1,cmp);
		int p=1,tag=0,flag=0;
		LL ans=0;
		for (int i=1;i<=tot;i++) cap[i]=c-c0+w[i];
		build(1,1,tot);
		while (!que.empty()) que.pop();
		for (int i=1;i<=tot;i++)
		{
			while (p<=n&&a[p].t<=i) que.push(mp(-a[p].y,p)),p++;
			if (ret[i]+tag>=0) continue;
			int ned=-ret[i]-tag;
			while (!que.empty()&&ned)
			{
				int y=-que.top().first,id=que.top().second,k=query(1,1,tot,a[id].t,tot);
				que.pop();
				if (!k) continue;
				int w=std::min(ned,std::min(a[id].x,k));
				ned-=w;ans+=(LL)y*w;a[id].x-=w;tag+=w;
				ins(1,1,tot,a[id].t,tot,-w);
				if (a[id].x&&cap[a[id].t]) que.push(mp(-y,id));
			}
			if (ned) {puts("-1");flag=1;break;}
		}
		if (!flag) printf("%lld\n",ans);
	}
	return 0;
}