#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int N,M;
char map[2005][2005];
inline int indeg(int n,int m)
{
	return
	(map[n-1][m]=='.') +
	(map[n+1][m]=='.') +
	(map[n][m-1]=='.') +
	(map[n][m+1]=='.') ;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%s",&map[i][1]);
	int cnt=0;
	queue<pair<int,int> >Q;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(map[i][j]=='.')
			{
				if(indeg(i,j)==1) Q.push(make_pair(i,j));
				if(indeg(i,j)==0)
				{
					puts("Not unique");
					return 0;
				}
			}
		}
	}
	int x,y;
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	while(!Q.empty())
	{
		pair<int,int> X=Q.front();
		x=X.first,y=X.second;
		Q.pop();
		if(map[x][y]=='.')
		{
			if(indeg(x,y)==0)
			{
				puts("Not unique");
				return 0;
			}
			if(map[x-1][y]=='.')
			{
				map[x-1][y]='^';
				map[x][y]='v';
				for(int i=0;i<4;i++)
				{
					int j=x-1+dx[i];
					int k=y+dy[i];
					if(map[j][k]=='.' && indeg(j,k)==1) Q.push(make_pair(j,k));
				}
			}
			if(map[x+1][y]=='.')
			{
				map[x][y]='^';
				map[x+1][y]='v';
				for(int i=0;i<4;i++)
				{
					int j=x+1+dx[i];
					int k=y+dy[i];
					if(map[j][k]=='.' && indeg(j,k)==1) Q.push(make_pair(j,k));
				}
			}
			if(map[x][y-1]=='.')
			{
				map[x][y-1]='<';
				map[x][y]='>';
				for(int i=0;i<4;i++)
				{
					int j=x+dx[i];
					int k=y-1+dy[i];
					if(map[j][k]=='.' && indeg(j,k)==1) Q.push(make_pair(j,k));
				}
			}
			if(map[x][y+1]=='.')
			{
				map[x][y]='<';
				map[x][y+1]='>';
				for(int i=0;i<4;i++)
				{
					int j=x+dx[i];
					int k=y+1+dy[i];
					if(map[j][k]=='.' && indeg(j,k)==1) Q.push(make_pair(j,k));
				}
			}
		}
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(map[i][j]=='.')
			{
				puts("Not unique");
				return 0;
			}
	for(int i=1;i<=N;i++) puts(&map[i][1]);
	return 0;
}