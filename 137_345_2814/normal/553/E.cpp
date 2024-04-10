#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 70000
#define M 105
double pi=acos(-1);
struct comp{double x,y;};
comp operator +(comp a,comp b){return (comp){a.x+b.x,a.y+b.y};}
comp operator -(comp a,comp b){return (comp){a.x-b.x,a.y-b.y};}
comp operator *(comp a,comp b){return (comp){a.x*b.x-a.y*b.y,a.y*b.x+b.y*a.x};}
comp fft[N],a[N],b[N];
int n,m,t,f,rev[N],v[M][3],s[M][N],dis[M],vis[M],head[M],su[M][N],cnt;
double dp[M][N],dp2[M][N];
struct edge{int t,next,v;}ed[M*2];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;}
void dij(int s)
{
	priority_queue<pair<long long,int> > st;
	st.push(make_pair(0,s));
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!st.empty())
	{
		int v=st.top().second;st.pop();
		if(vis[v])continue;vis[v]=1;
		for(int i=head[v];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[v]+ed[i].v)
		dis[ed[i].t]=dis[v]+ed[i].v,st.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
void dft(int s,comp *a,int t)
{
	for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)+((i&1)*(s>>1)),fft[rev[i]]=a[i];
	for(int l=2;l<=s;l<<=1)
	{
		comp t1=(comp){cos(pi*2/l),t*sin(pi*2/l)};
		for(int i=0;i<s;i+=l)
		{
			comp s=(comp){1,0};
			for(int j=i;j<i+(l>>1);j++,s=s*t1)
			{
				comp s1=fft[j],s2=fft[j+(l>>1)]*s;
				fft[j]=s1+s2;fft[j+(l>>1)]=s1-s2;
			}
		}
	}
	for(int i=0;i<s;i++){a[i]=fft[i];if(t==-1)a[i].x/=s,a[i].y/=s;}
}
void cdq(int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<n;i++)dp2[i][l]=1e17;
		for(int i=1;i<=m;i++)
		{
			double tp=1-su[i][t-l]/1e5;
			dp[i][l]+=tp*(f+dis[v[i][1]])+v[i][2];
			if(dp[i][l]<dp2[v[i][0]][l])dp2[v[i][0]][l]=dp[i][l];
		}
//		printf("%d ",l);for(int i=1;i<=n;i++)printf("%.10lf ",dp2[i][l]);
//		printf("\n");
		return;
	}
	int mid=(l+r)>>1;
	cdq(mid+1,r);
	for(int i=1;i<=m;i++)
	{
		int l1=1;while(l1<(r-l)*3/2+5)l1<<=1;
		for(int j=0;j<l1;j++)a[j].x=a[j].y=b[j].x=b[j].y=0;
		for(int j=mid+1;j<=r;j++)a[j-mid].x=dp2[v[i][1]][j];
		for(int j=1;j<=r-l+1;j++)b[r-l+1-j].x=s[i][j]/1e5;
		dft(l1,a,1);dft(l1,b,1);for(int j=0;j<l1;j++)a[j]=a[j]*b[j];dft(l1,a,-1);
		for(int j=l;j<=mid;j++)dp[i][j]+=a[j+r-l+1-mid].x;
	}
	cdq(l,mid);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&t,&f);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
		adde(v[i][1],v[i][0],v[i][2]);
		for(int j=1;j<=t;j++)scanf("%d",&s[i][j]),su[i][j]=su[i][j-1]+s[i][j];
	}
	dij(n);cdq(0,t);
	printf("%.10lf\n",dp2[1][0]);
}