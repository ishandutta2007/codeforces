#include<cstdio>
int n,m,t,la,ans=0;bool ok,hori_ok=0,vert_ok=0;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
char ch[1002][1002];
bool vis[1002][1002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check_hori()
{
	for(int i=1;i<=n;++i)
	{
		t=0,ok=0;
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='#')
			{
				ok=1,la=j;
				break;
			}
		if(!ok)hori_ok=1;
		for(int j=la;j<=m;++j)
			if(ch[i][j]=='#')
			{
				++t;
				if(t>1)
				{
					printf("-1");
					return 1;
				}
				while(j<m && ch[i][j+1]=='#')++j;
			}
	}
	return 0;
}
inline bool check_vert()
{
	for(int j=1;j<=m;++j)
	{
		t=0,ok=0;
		for(int i=1;i<=n;++i)
			if(ch[i][j]=='#')
			{
				ok=1,la=i;
				break;
			}
		if(!ok)vert_ok=1;
		for(int i=la;i<=n;++i)
			if(ch[i][j]=='#')
			{
				++t;
				if(t>1)
				{
					printf("-1");
					return 1;
				}
				while(i<n && ch[i+1][j]=='#')++i;
			}
	}
	return 0;
}
inline void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0,x1,y1;i<4;++i)
	{
		x1=x+dx[i],y1=y+dy[i];
		if(ch[x1][y1]=='#' && !vis[x1][y1])
			dfs(x1,y1);
	}
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)
		scanf("%s",ch[i]+1);
	if(check_hori())return 0;
	if(check_vert())return 0;
	if((hori_ok && !vert_ok) || (!hori_ok && vert_ok))
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='#' && !vis[i][j])
				++ans,dfs(i,j);
	printf("%d",ans);
	return 0;
}