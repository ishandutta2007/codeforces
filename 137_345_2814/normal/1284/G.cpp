#include<cstdio>
#include<queue>
using namespace std;
#define N 22
#define M 805
int T,n,m,ct,t[M][2],cl[M],is[M],f1[M],f2[M],fr[M],su;
char s[N][N],as[N*2][N*2];
int c1[M],fa[M];
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	ct=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='O'&&i+j>2)
	{
		if(i<n&&s[i+1][j]=='O')t[++ct][0]=(i-1)*m+j,t[ct][1]=i*m+j,cl[ct]=t[ct][(i+j)&1];
		if(j<m&&s[i][j+1]=='O')t[++ct][0]=(i-1)*m+j,t[ct][1]=(i-1)*m+j+1,cl[ct]=t[ct][(i+j)&1];
	}
	su=0;
	for(int i=1;i<=ct;i++)is[i]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='O'&&(~(i+j)&1)&&i+j>2)su+=2;
	for(int ti=1;ti<=su;ti++)
	{
		for(int i=1;i<=n*m;i++)fa[i]=i,c1[i]=0;c1[1]++;
		for(int i=1;i<=ct;i++)if(is[i])fa[finds(t[i][0])]=finds(t[i][1]),c1[cl[i]]++,f1[i]=f2[i]=fr[i]=0;
		for(int i=1;i<=ct;i++)if(!is[i])f1[i]=finds(t[i][0])!=finds(t[i][1]),f2[i]=c1[cl[i]]<2,fr[i]=0;
		queue<int> qu;
		for(int i=1;i<=ct;i++)if(f1[i])qu.push(i),fr[i]=-1;
		int rs=0;
		while(!qu.empty()&&!rs)
		{
			int u=qu.front();qu.pop();
			if(is[u])
			{
				for(int i=1;i<=n*m;i++)fa[i]=i;
				for(int i=1;i<=ct;i++)if(is[i]&&i!=u)fa[finds(t[i][0])]=finds(t[i][1]);
				for(int i=1;i<=ct;i++)if(!is[i]&&!fr[i]&&finds(t[i][0])!=finds(t[i][1]))fr[i]=u,qu.push(i);
			}
			else
			{
				if(f2[u])rs=u;
				for(int i=1;i<=n*m;i++)c1[i]=0;c1[1]++;
				for(int i=1;i<=ct;i++)if(is[i])c1[cl[i]]++;
				for(int i=1;i<=ct;i++)if(is[i]&&!fr[i]&&(c1[cl[u]]<2||cl[i]==cl[u]))fr[i]=u,qu.push(i);
			}
		}
		if(!rs){printf("NO\n");return;}
		while(rs!=-1)is[rs]^=1,rs=fr[rs];
	}
	for(int i=1;i<=n*m;i++)fa[i]=i;
	if(s[1][2]=='O')t[++ct][0]=1,t[ct][1]=2,is[ct]=0;
	if(s[2][1]=='O')t[++ct][0]=1,t[ct][1]=m+1,is[ct]=0;
	for(int i=1;i<=ct;i++)if(is[i])fa[finds(t[i][0])]=finds(t[i][1]);
	for(int i=1;i<=ct;i++)if(finds(t[i][0])!=finds(t[i][1]))is[i]=1,fa[finds(t[i][0])]=finds(t[i][1]);
	for(int i=1;i<n*2;i++)for(int j=1;j<m*2;j++)as[i][j]=(i&j&1)?s[(i+1)>>1][(j+1)>>1]:' ';
	for(int i=1;i<=ct;i++)if(is[i])
	{
		int v1=t[i][0],v2=t[i][1],sx=(v1-1)/m+1,sy=v1-(sx-1)*m,tx=(v2-1)/m+1,ty=v2-(tx-1)*m;
		as[sx+tx-1][sy+ty-1]=sx==tx?'-':'|';
	}
	printf("YES\n");
	for(int i=1;i<n*2;i++)printf("%s\n",as[i]+1);
	for(int i=1;i<n*2;i++)for(int j=1;j<m*2;j++)as[i][j]=0;
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
}