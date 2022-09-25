#include<cstdio>
#include<map>
using namespace std;
#define N 400040
struct edge{int f,t,l,r,s;} s1[N];
edge st[20][N];int n,m,k,fa[N],sz[N],dis[N],ct[20],q[20][N],as[N],que[N][2],a,b,c,d;
int finds(int x){return fa[x]==x?x:finds(fa[x]);}
int get(int x){int ans=0;while(fa[x]!=x){ans^=dis[x];x=fa[x];}return ans;}
struct Xor{
	int a[30];
	Xor(){for(int i=0;i<=29;i++)a[i]=0;}
	void insert(int x)
	{
		for(int i=29;i>=0;i--)
		{
			int tmp=x^a[i];
			if(a[i]==0&&(x>>i))
			{
				a[i]=x;
				return;
			}
			if(tmp<x)x=tmp;
		}
	}
	int query(int s)
	{
		for(int i=29;i>=0;i--)
		if((s^a[i])<s)s^=a[i];
		return s;
	}
}st2[21];
void un(int x,int y,int t,int v,int s)
{
	int a=finds(x),a1=finds(y),b=get(x),b1=get(y);
	if(a==a1)
	{
		int tmp=b^b1^s;
		st2[v].insert(tmp);
		return;
	}
	if(sz[a]<sz[a1])
	a^=a1^=a^=a1;
	q[v][++ct[v]]=a1;
	fa[a1]=a,sz[a]+=sz[a1],dis[a1]=s^b^b1;
}
void cdq(int l,int r,int cnt,int dep)
{
	for(int i=1;i<=cnt;i++)
	if(st[dep][i].l<=l&&st[dep][i].r>=r)
	un(st[dep][i].f,st[dep][i].t,i,dep,st[dep][i].s);
	if(l==r)
	{
		if(que[l][0])
		{
			int tmp=get(que[l][0])^get(que[l][1]);
			as[l]=st2[dep].query(tmp);
		}
		for(int i=1;i<=ct[dep];i++)
		{
			int t=q[dep][i];
			fa[t]=t,dis[t]=0;
		}
		ct[dep]=0;
		return;
	}
	int tmp=0,mid=(l+r)>>1;
	for(int i=1;i<=cnt;i++)
	if(st[dep][i].l<=mid&&!(st[dep][i].l<=l&&st[dep][i].r>=r))
	st[dep+1][++tmp]=st[dep][i];
	st2[dep+1]=st2[dep];
	cdq(l,mid,tmp,dep+1);
	tmp=0;
	for(int i=1;i<=cnt;i++)
	if(st[dep][i].r>mid&&!(st[dep][i].l<=l&&st[dep][i].r>=r))
	st[dep+1][++tmp]=st[dep][i];
	st2[dep+1]=st2[dep];
	cdq(mid+1,r,tmp,dep+1);
	for(int i=1;i<=ct[dep];i++)
	{
		int t=q[dep][i];
		fa[t]=t,dis[t]=0;
	}
	ct[dep]=0;
}
map<long long,int> s3;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&st[1][i].f,&st[1][i].t,&st[1][i].s),st[1][i].l=1;
		s3[1ll*st[1][i].f*1000000+st[1][i].t]=i;
	}
	int cnt=m;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			scanf("%d",&d);
			st[1][++cnt]=(edge){b,c,i,0,d};
			s3[1ll*st[1][cnt].f*1000000+st[1][cnt].t]=cnt;
		}
		if(a==2)
		{
			long long tmp=1ll*b*1000000+c,tmp2=1ll*c*1000000+b;
			int ans=s3[tmp];
			if(ans==0)ans=s3[tmp2];
			st[1][ans].r=i;
			s3[tmp]=s3[tmp2]=0;
		}
		if(a==3)
		que[i][0]=b,que[i][1]=c;
	}
	for(int i=1;i<=cnt;i++)
	if(!st[1][i].r)
	st[1][i].r=k;
	cdq(1,k,cnt,1);
	for(int i=1;i<=k;i++)
	if(que[i][0])
	printf("%d\n",as[i]);
}