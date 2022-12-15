#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,m,T;
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
inline bool inarea(int x,int y)
{
	return x>0&&x<=n&&y>0&&y<=m;
}
int siz[1010][1010],id[1010][1010],idcnt;
char s[1010][1010];
bool vis[1010][1010];
void bfs(int x,int y)
{
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	id[x][y]=++idcnt;
	vis[x][y]=1;
	int cur=1;
	while(!q.empty())
	{
		pair<int,int> fr=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			pair<int,int> nxt=make_pair(fr.first+d[i][0],fr.second+d[i][1]);
			if(inarea(nxt.first,nxt.second)&&!vis[nxt.first][nxt.second]&&s[nxt.first][nxt.second]==s[fr.first][fr.second])
			{
				cur++;
				id[nxt.first][nxt.second]=idcnt;
				vis[nxt.first][nxt.second]=1;
//				pos[nxt.first][nxt.second]=make_pair(x,y);
				q.push(nxt);
			}
		}
	}
	siz[x][y]=cur;
}
int dis[1000010];
vector<int> v[1000010];
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				bfs(i,j);
				f|=(siz[i][j]!=1);
			}
		}
	}
	if(!f)
	{
		while(T--)
		{
			int x,y,p;
			scanf("%d%d%d",&x,&y,&p);
			putchar(s[x][y]);putchar('\n');
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=m&&s[i][j]!=s[i][j+1])
			{
				v[id[i][j]].push_back(id[i][j+1]);
				v[id[i][j+1]].push_back(id[i][j]);
			}
			if(i!=n&&s[i][j]!=s[i+1][j])
			{
				v[id[i][j]].push_back(id[i+1][j]);
				v[id[i+1][j]].push_back(id[i][j]);
			}
		}
	}
	queue<int> q;
	memset(dis,255,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(siz[i][j]>1)
			{
				q.push(id[i][j]);
				dis[id[i][j]]=0;
			}
		}
	}
	while(!q.empty())
	{
		int fr=q.front();q.pop();
		for(int &x:v[fr])
		{
			if(dis[x]==-1)
			{
				dis[x]=dis[fr]+1;
				q.push(x);
			}
		}
	}
	while(T--)
	{
		int x,y;
		ll p;
		scanf("%d%d%lld",&x,&y,&p);
		if(p<=dis[id[x][y]])printf("%c\n",s[x][y]);
		else if(p%2!=dis[id[x][y]]%2)printf("%d\n",(s[x][y]-'0')^1);
		else printf("%c\n",s[x][y]);
	}
	return 0;
}