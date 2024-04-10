#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500005;
struct node
{
	int id,x,y;
}q[N];
int n,m,i,j,k,p[N],q1[N],top1,q2[N],top2,mn[N*5],mncnt[N*5],add[N*5];
long long ans[N],Cnt[N*5],Add[N*5],h;
bool cmp(node a,node b)
{
	return a.y<b.y;
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		mn[o]=1,mncnt[o]=1,add[o]=Add[o]=Cnt[o]=0;
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	mncnt[o]=0;
	if(mn[o]==mn[o<<1])
		mncnt[o]+=mncnt[o<<1];
	if(mn[o]==mn[o<<1|1])
		mncnt[o]+=mncnt[o<<1|1];
}
void pushdown(int o,int l,int r)
{
	add[o<<1]+=add[o],add[o<<1|1]+=add[o];
	mn[o<<1]+=add[o],mn[o<<1|1]+=add[o];
	if(mn[o<<1]==mn[o])
		Add[o<<1]+=Add[o],Cnt[o<<1]+=Add[o]*mncnt[o<<1];
	if(mn[o<<1|1]==mn[o])
		Add[o<<1|1]+=Add[o],Cnt[o<<1|1]+=Add[o]*mncnt[o<<1|1];
	Add[o]=0;
	add[o]=0;
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		mn[o]+=z;
		add[o]+=z;
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	mncnt[o]=0;
	if(mn[o]==mn[o<<1])
		mncnt[o]+=mncnt[o<<1];
	if(mn[o]==mn[o<<1|1])
		mncnt[o]+=mncnt[o<<1|1];
	Cnt[o]=Cnt[o<<1]+Cnt[o<<1|1];
}
void query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		h+=Cnt[o];
		return;
	}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(x<=mid)
		query(o<<1,l,mid,x,y);
	if(y>mid)
		query(o<<1|1,mid+1,r,x,y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",p+i);
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		q[i].id=i;
		scanf("%d%d",&q[i].x,&q[i].y);
	}
	for(i=1;i<=n;++i)
		if(p[i]!=i)
			break;
	if(i>n)
	{
		for(i=1;i<=m;++i)
			printf("%lld\n",1ll*(q[i].y-q[i].x+1)*(q[i].y-q[i].x)/2+q[i].y-q[i].x+1);
		return 0;
	}
	sort(q+1,q+1+m,cmp);
	built(1,1,n);
	top1=top2=0;
	for(i=1,j=1;i<=n;++i)
	{
		while(top1>0&&p[q1[top1]]<p[i])
		{
			update(1,1,n,q1[top1-1]+1,q1[top1],p[i]-p[q1[top1]]);
			--top1;
		}
		q1[++top1]=i;
		while(top2>0&&p[q2[top2]]>p[i])
		{
			update(1,1,n,q2[top2-1]+1,q2[top2],-(p[i]-p[q2[top2]]));
			--top2;
		}
		q2[++top2]=i;
		if(i>1)
			update(1,1,n,1,i-1,-1);
		update(1,1,n,i,i,-1);
		Add[1]++;
		if(mn[1]==0)
			Cnt[1]+=mncnt[1];
		while(j<=m&&q[j].y<=i)
		{
			h=0;
			query(1,1,n,q[j].x,i);
			ans[q[j].id]=h;
			++j;
		}
	}
	for(i=1;i<=m;++i)
		printf("%lld\n",ans[i]);
	return 0;
}