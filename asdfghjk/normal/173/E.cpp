#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
struct node
{
	int id,r,a;
}a[N];
struct mode
{
	int id,num;
}b[N];
struct oode
{
	int id,x,y;
}c[N];
int n,K,q,i,j,k,h[N],ch[N*30][2],mx[N*30],chd[N*30][2],sum[N*30],cnt,tot,ans[N];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
bool cmq(mode g,mode h)
{
	return a[g.id].r>a[h.id].r;
}
bool cmr(oode g,oode h)
{
	return max(a[g.x].r,a[g.y].r)>max(a[h.x].r,a[h.y].r);
}
void update(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		mx[o]=max(mx[o],y);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
	{
		if(!ch[o][0])
			ch[o][0]=++cnt;
		update(ch[o][0],l,mid,x,y);
	}
	else
	{
		if(!ch[o][1])
			ch[o][1]=++cnt;
		update(ch[o][1],mid+1,r,x,y);
	}
	mx[o]=max(mx[ch[o][0]],mx[ch[o][1]]);
}
int query(int o,int l,int r,int x,int y)
{
	if(!o)
		return 0;
	if(l>=x&&r<=y)
		return mx[o];
	int mid=l+r>>1,rtn=0;
	if(x<=mid)
		rtn=query(ch[o][0],l,mid,x,y);
	if(y>mid)
		rtn=max(rtn,query(ch[o][1],mid+1,r,x,y));
	return rtn;
}
void Update(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		sum[o]+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
	{
		if(!chd[o][0])
			chd[o][0]=++tot;
		Update(chd[o][0],l,mid,x,y);
	}
	else
	{
		if(!chd[o][1])
			chd[o][1]=++tot;
		Update(chd[o][1],mid+1,r,x,y);
	}
	sum[o]=sum[chd[o][0]]+sum[chd[o][1]];
}
int Query(int o,int l,int r,int x,int y)
{
	if(!o)
		return 0;
	if(l>=x&&r<=y)
		return sum[o];
	int mid=l+r>>1,rtn=0;
	if(x<=mid)
		rtn=Query(chd[o][0],l,mid,x,y);
	if(y>mid)
		rtn+=Query(chd[o][1],mid+1,r,x,y);
	return rtn;
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
	{
		a[i].id=i;
		scanf("%d",&a[i].r);
	}
	for(i=1;i<=n;++i)
		scanf("%d",&a[i].a);
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i)
		h[a[i].id]=i;
	tot=1;
	for(i=1;i<=n;i=j)
	{
		for(j=i;j<=n&&a[i].r==a[j].r;++j)
			Update(1,1,1000000000,a[j].a,1);
		for(j=i;j<=n&&a[i].r==a[j].r;++j)
			b[j]=(mode){j,Query(1,1,1000000000,max(a[j].a-K,1),min(a[j].a+K,1000000000))};
	}
	scanf("%d",&q);
	for(i=1;i<=q;++i)
	{
		scanf("%d%d",&j,&k);
		c[i].x=h[j],c[i].y=h[k];
		if(a[c[i].x].a>a[c[i].y].a)
			swap(c[i].x,c[i].y);
		c[i].id=i;
	}
	sort(b+1,b+1+n,cmq);
	sort(c+1,c+1+q,cmr);
	cnt=1;
	for(i=j=1;i<=q;++i)
	{
		while(j<=n&&a[b[j].id].r>=max(a[c[i].x].r,a[c[i].y].r))
		{
			update(1,1,1000000000,a[b[j].id].a,b[j].num);
			++j;
		}
		if(a[c[i].y].a-a[c[i].x].a>2*K)
		{
			ans[c[i].id]=-1;
			continue;
		}
		ans[c[i].id]=query(1,1,1000000000,max(a[c[i].y].a-K,1),min(a[c[i].x].a+K,1000000000));
		if(ans[c[i].id]==0)
			ans[c[i].id]=-1;
	}
	for(i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}