#include<map>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int inf=1e9+25;
map<int,int> mp;int num=0;
int tim=0,vis[100010];
int n,k,N=0;
struct node{
	int a,num,op;
}b[500010];
struct point{
	int l,x,r,s;
}a[100010];
struct trnode{
	int lc,rc,c;
}tr[6000010];int tot=0,root[100010];
struct query{
	int op,x,l,r,y;
}q[500010];
void update(int &x,int l,int r,int k)
{
	if(!x) x=++tot;
	if(l==r) {tr[x].c++;return;}
	int mid=(l+r)/2;
	if(k<=mid) update(tr[x].lc,l,mid,k);
	else update(tr[x].rc,mid+1,r,k);
	tr[x].c=tr[tr[x].lc].c+tr[tr[x].rc].c;
}
int findans(int x,int l,int r,int fl,int fr)
{
	if(!x) return 0;
	if(l==fl&&r==fr) return tr[x].c;
	int mid=(l+r)/2;
	if(fr<=mid) return findans(tr[x].lc,l,mid,fl,fr);
	if(fl>mid) return findans(tr[x].rc,mid+1,r,fl,fr);
	return findans(tr[x].lc,l,mid,fl,mid)+findans(tr[x].rc,mid+1,r,mid+1,fr);
}
bool cmp(node a,node b) {return a.a<b.a;}
bool cmp1(query a,query b) {return a.x==b.x?a.op>b.op:a.x<b.x;}
bool cmp3(point a,point b) {return a.x<b.x;}
LL ans=0;
void solve(int l,int r)
{
	tim++;
	for(int i=l;i<=r;i++)
	{
		int c=mp[a[i].s];
		if(vis[c]!=tim) vis[c]=tim,root[c]=0;
		root[c]++;
	}
	int re=0;
	for(int i=l;i<=r;i++)
		for(int j=a[i].s-k;j<=a[i].s+k;j++) if(mp[j]&&vis[mp[j]]==tim) re+=root[mp[j]];
	//printf("%d %d:%d\n",l,r,re);
	ans=ans-(re-(r-l+1))/2-(r-l+1);
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].l,&a[i].s);
		int t=a[i].l;a[i].l=max(0,a[i].x-t);a[i].r=a[i].x+t;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		b[++cnt].num=i;b[cnt].op=1;b[cnt].a=a[i].l;
		b[++cnt].num=i;b[cnt].op=2;b[cnt].a=a[i].x;
		b[++cnt].num=i;b[cnt].op=3;b[cnt].a=a[i].r;
	}
	sort(b+1,b+cnt+1,cmp);
	//for(int i=1;i<=n;i++) printf("%d %d %d\n",a[i].l,a[i].x,a[i].r);
	for(int i=1;i<=cnt;i++)
	{
		if(i==1||b[i].a!=b[i-1].a) N++;
		if(b[i].op==1) a[b[i].num].l=N;
		if(b[i].op==2) a[b[i].num].x=N;
		if(b[i].op==3) a[b[i].num].r=N;
	}
	//for(int i=1;i<=n;i++) printf("a:%d %d %d %d\n",a[i].l,a[i].x,a[i].r,a[i].s);
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		q[++cnt].op=1;q[cnt].x=a[i].x;q[cnt].l=a[i].s-k;q[cnt].r=a[i].s+k;q[cnt].y=a[i].x;
		q[++cnt].op=2;q[cnt].x=a[i].l-1;q[cnt].l=a[i].s-k;q[cnt].r=a[i].s+k;q[cnt].y=a[i].x;
		q[++cnt].op=3;q[cnt].x=a[i].x;q[cnt].l=a[i].s;q[cnt].r=a[i].r;
	}
	sort(q+1,q+cnt+1,cmp1);
	//for(int i=1;i<=cnt;i++) printf("q:%d %d %d %d %d\n",q[i].op,q[i].x,q[i].l,q[i].r,q[i].y);
	for(int i=1;i<=cnt;i++)
	{
		if(q[i].op==3)
		{
			int c=q[i].l;if(!mp[c]) mp[c]=++num;
			update(root[mp[c]],1,N,q[i].r);
		}
		else
		{
			int t=0;
			for(int j=q[i].l;j<=q[i].r;j++)
			{
				if(!mp[j]) continue;
				t+=findans(root[mp[j]],1,N,q[i].y,N);
			}
			if(q[i].op==1) ans+=t;
			else ans-=t;
		}
		//printf("%d:%lld\n",i,ans);
	}
	memset(root,0,sizeof(root));
	sort(a+1,a+n+1,cmp3);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		if(i==1||a[i].x==a[i-1].x) continue;
		else solve(l,i-1),l=i;
	}
	solve(l,n);
	printf("%lld\n",ans);
}