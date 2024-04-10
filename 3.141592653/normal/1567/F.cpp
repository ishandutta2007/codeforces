#include<bits/stdc++.h>
int n,m;
char s[1<<10][1<<10];
int w[1<<10][1<<10];
struct pii{int dx,dy;};
std::vector<pii>v[1<<10][1<<10];
void link(int x,int y,int xx,int yy)
{
	v[x][y].push_back(pii{xx,yy});
	v[xx][yy].push_back(pii{x,y});
}
void init(int x,int y)
{
	int cnt=(s[x-1][y]=='.')+(s[x+1][y]=='.')+(s[x][y-1]=='.')+(s[x][y+1]=='.');
	if(cnt&1){puts("NO");exit(0);}
	if(cnt==4)w[x][y]=10,link(x-1,y,x,y-1),link(x+1,y,x,y+1);
	if(cnt==2)
	{
		w[x][y]=5;
		if(s[x-1][y]=='.'&&s[x+1][y]=='.')link(x-1,y,x+1,y);
		if(s[x-1][y]=='.'&&s[x][y+1]=='.')link(x-1,y,x,y+1);
		if(s[x][y-1]=='.'&&s[x+1][y]=='.')link(x,y-1,x+1,y);
		if(s[x][y-1]=='.'&&s[x][y+1]=='.')link(x,y-1,x,y+1);
		if(s[x+1][y]=='.'&&s[x][y+1]=='.')link(x+1,y,x,y+1);
		if(s[x-1][y]=='.'&&s[x][y-1]=='.')link(x-1,y,x,y-1);
	}
}
void dfs(int x,int y,int d=1)
{
	w[x][y]=d;
	//printf("%d %d %d %u\n",x,y,d,v[x][y].size());
	for(pii z:v[x][y])
	{
		//printf("%d %d\n",z.dx,z.dy);
		if(!w[z.dx][z.dy])dfs(z.dx,z.dy,5-d);
	}
}
int main()
{
	register int i,ii;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=2;i<n;i++)for(ii=2;ii<m;ii++)
		if(s[i][ii]=='X')init(i,ii);
	for(i=1;i<=n;i++)for(ii=1;ii<=m;ii++)
		if(s[i][ii]!='X')if(!w[i][ii])
		{
			dfs(i,ii);
			//printf("%d %d\n",i,ii);
		}
	puts("YES");
	for(i=1;i<=n;i++,puts(""))for(ii=1;ii<=m;ii++)printf("%d ",w[i][ii]);
}