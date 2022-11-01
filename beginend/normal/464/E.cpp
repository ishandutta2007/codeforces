#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;
typedef unsigned long long ull;

const int N=100005;
const ull BAS=233333;
const int MOD=1000000007;

int n,m,cnt,last[N],dis[N],stack[N],sz,mx,bin[N*2],s,T,pre[N];
bool vis[N];
struct edge{int to,next,w;}e[N*2];
struct tree{int l,r,s;ull hash;}t[N*200];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void updata(int d)
{
	t[d].s=t[t[d].l].s+t[t[d].r].s;
	ull x1=t[t[d].l].hash,x2=t[t[d].r].hash;
	t[d].hash=((((x1*BAS+x2)^x1)*BAS)^x2)*BAS;
}

bool cmp(int d,int p,int l,int r)
{
	if (l==r) return t[d].s>=t[p].s;
	int mid=(l+r)/2;
	if (t[t[d].r].hash!=t[t[p].r].hash) return cmp(t[d].r,t[p].r,mid+1,r);
	else return cmp(t[d].l,t[p].l,l,mid);
}

struct data
{
	int x,y;
	
	bool operator < (const data &d) const
	{
		return cmp(x,d.x,0,mx);
	}
};
priority_queue<data> que;

void del(int &d,int l,int r,int x,int y)
{
	if (l==x&&r==y) {d=0;return;}
	int p=d;d=++sz;t[d]=t[p];
	int mid=(l+r)/2;
	if (x<=mid) del(t[d].l,l,mid,x,min(y,mid));
	if (y>mid) del(t[d].r,mid+1,r,max(x,mid+1),y);
	updata(d);
}

void ins(int &d,int l,int r,int x)
{
	int p=d;d=++sz;t[d]=t[p];
	if (l==r) {t[d].hash=l+123;t[d].s=1;return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
	updata(d);
}

int query(int d,int l,int r,int x)
{
	if (l==r) return !t[d].s?l:-1;
	int mid=(l+r)/2;
	if (x>mid) return query(t[d].r,mid+1,r,x);
	int ans=query(t[d].l,l,mid,x);
	if (ans>-1) return ans;
	else return query(t[d].r,mid+1,r,x);
}

int add(int r,int w)
{
	int p=query(r,0,mx,w);
	if (p>w) del(r,0,mx,w,p-1);
	ins(r,0,mx,p);
	return r;
}

int get_val(int d,int l,int r)
{
	if (!d) return 0;
	if (l==r) return bin[l];
	int mid=(l+r)/2;
	return (get_val(t[d].l,l,mid)+get_val(t[d].r,mid+1,r))%MOD;
}

void dij()
{
	dis[s]=++sz;que.push((data){dis[s],s});
	while (!que.empty())
	{
		int u=que.top().y;que.pop();
		while (!que.empty()&&vis[u]) u=que.top().y,que.pop();
		if (vis[u]) break;
		vis[u]=1;
		for (int i=last[u];i;i=e[i].next)
		{
			int r=add(dis[u],e[i].w);
			if (!dis[e[i].to]||!cmp(r,dis[e[i].to],0,mx))
			{
				pre[e[i].to]=u;
				dis[e[i].to]=r;
				que.push((data){r,e[i].to});
			}
		}
	}
}

int main()
{
	//freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);mx=max(mx,z);
	}
	mx+=300;
	bin[0]=1;
	for (int i=1;i<=mx;i++) bin[i]=bin[i-1]*2%MOD;
	scanf("%d%d",&s,&T);
	dij();
	if (!dis[T]) {puts("-1");return 0;}
	printf("%d\n",get_val(dis[T],0,mx));
	int x=T,top=1;stack[1]=T;
	while (x!=s) x=pre[x],stack[++top]=x;
	printf("%d\n",top);
	while (top) printf("%d ",stack[top]),top--;
	return 0;
}