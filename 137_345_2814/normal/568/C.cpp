#include<cstdio>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 505
int head[N],n,m,cnt,dfn[N],low[N],scc[N],ct1,ct2,head2[N],cnt2,s[N*N][2],vl[N],le,a,b,is2[N],is3[N];
char c[5],d[5],is[32],t[N],as[N];
struct edge{int t,next;}ed[N*N],ed2[N*N];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
void adde2(int f,int t){ed2[++cnt2]=(edge){t,head2[f]};head2[f]=cnt2;}
stack<int> tp;
void dfs1(int u)
{
	dfn[u]=low[u]=++ct1;
	tp.push(u);
	for(int i=head[u];i;i=ed[i].next)
	{
		if(!dfn[ed[i].t])dfs1(ed[i].t),low[u]=min(low[u],low[ed[i].t]);
		else if(!scc[ed[i].t])low[u]=min(low[u],dfn[ed[i].t]);
	}
	if(dfn[u]==low[u])
	{
		int s=tp.top(),id=++ct2;tp.pop();
		scc[s]=id;
		while(s!=u)
		s=tp.top(),tp.pop(),scc[s]=id;
	}
}
bool check()
{
	for(int i=1;i<=ct2;i++)is2[i]=-1;
	for(int i=1;i<=n;i++)
	if(is3[i]==0){if(is2[scc[i]]==0)return 0;is2[scc[i]]=1,is2[scc[i+n]]=0;}
	else if(is3[i]==1){if(is2[scc[i+n]]==0)return 0;is2[scc[i+n]]=1,is2[scc[i]]=0;}
	for(int i=ct2;i>=1;i--)if(is2[i]==1)
	for(int j=head2[i];j;j=ed2[j].next)
	{
		if(is2[ed2[j].t]==0)return 0;
		is2[ed2[j].t]=1;
	}
	for(int i=ct2;i>=1;i--)
	for(int j=head2[i];j;j=ed2[j].next)
	if(is2[ed2[j].t]==0)
	{
		if(is2[i]==1)return 0;
		is2[i]|=is2[ed2[j].t];
	}
	for(int i=1;i<=n;i++)if(is2[scc[i]]==is2[scc[i+n]]&&is2[scc[i]]>=0)return 0;
	return 1;
}
int main()
{
	scanf("%s",is+1);le=strlen(is+1);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%s%d%s",&a,c+1,&b,d+1);
		s[i][0]=a+(c[1]=='V'?n:0);
		s[i][1]=b+(d[1]=='V'?n:0);
		adde(s[i][0],s[i][1]);
		adde(s[i][1]+(s[i][1]>n?-n:n),s[i][0]+(s[i][0]>n?-n:n));
	}
	scanf("%s",t+1);
	for(int i=1;i<=n*2;i++)if(!dfn[i])dfs1(i);
	for(int i=1;i<=n;i++)if(scc[i]==scc[i+n]){printf("-1\n");return 0;}
	for(int i=1;i<=m;i++)
	if(scc[s[i][0]]!=scc[s[i][1]])adde2(scc[s[i][0]],scc[s[i][1]]),adde2(scc[s[i][1]+(s[i][1]>n?-n:n)],scc[s[i][0]+(s[i][0]>n?-n:n)]);
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n;j++)is3[j]=-1;
		for(int j=1;j<i;j++)is3[j]=is[t[j]-'a'+1]=='V';
		int l1=0,l2=0;
		for(int j=t[i]-'a'+1+(i!=n);j<=le;j++)
		if(is[j]=='V')l2=1;
		else l1=1;
		if(!l1&&!l2)continue;
		else if(!l1)is3[i]=1;
		else if(!l2)is3[i]=0;
		else is3[i]=-1;
		for(int j=i+1;j<=n;j++)
		{
			int l1=0,l2=0;
			for(int k=1;k<=le;k++)
			if(is[k]=='V')l2=1;
			else l1=1;
			if(!l1&&!l2)continue;
			else if(!l1)is3[j]=1;
			else if(!l2)is3[j]=0;
			else is3[j]=-1;
		}
		if(check())
		{
			for(int j=1;j<i;j++)as[j]=t[j];
			is3[i]=0;int f1=check();
			is3[i]=1;int f2=check();
			if(is[t[i]-'a'+1]=='V')
			{
				if(f2){for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='V')as[i]=k+'a'-1,is3[i]=1;}
				if(!f2||!as[i]) for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='C')as[i]=k+'a'-1,is3[i]=0;
				if(!as[i]){for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='V')as[i]=k+'a'-1,is3[i]=1;}
			}
			else
			{
				if(f1){for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='C')as[i]=k+'a'-1,is3[i]=0;}
				if(!f1||!as[i]) for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='V')as[i]=k+'a'-1,is3[i]=1;
				if(!as[i]){for(int k=le;k>t[i]-'a'+1-(i==n);k--)if(is[k]=='C')as[i]=k+'a'-1,is3[i]=0;}
			}
			for(int j=i+1;j<=n;j++)
			{
				is3[j]=0;int f1=check();
				is3[j]=1;int f2=check();
				if(is[1]=='V')
				{
					if(f2){for(int k=le;k>=1;k--)if(is[k]=='V')as[j]=k+'a'-1,is3[j]=1;}
					if(!f2||!as[i]) for(int k=le;k>=1;k--)if(is[k]=='C')as[j]=k+'a'-1,is3[j]=0;
					if(!as[i]){for(int k=le;k>=1;k--)if(is[k]=='V')as[j]=k+'a'-1,is3[j]=1;}
				}
				else
				{
					if(f1){for(int k=le;k>=1;k--)if(is[k]=='C')as[j]=k+'a'-1,is3[j]=0;}
					if(!f1||!as[i]) for(int k=le;k>=1;k--)if(is[k]=='V')as[j]=k+'a'-1,is3[j]=1;
					if(!as[i]){for(int k=le;k>=1;k--)if(is[k]=='C')as[j]=k+'a'-1,is3[j]=0;}
				}
			}
			printf("%s",as+1);return 0;
		}
	}
	printf("-1\n");
}