#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int,int> >connexion[200];
int N,M;
bool visited[200];
void dfs(int s,int c)
{
	if(visited[s]) return;
	visited[s]=true;
	for(int i=0;i<connexion[s].size();i++)
		if(connexion[s][i].second==c)
			dfs(connexion[s][i].first,c);
	return;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		x--;y--;
		connexion[x].push_back(make_pair(y,t));
		connexion[y].push_back(make_pair(x,t));
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		s--;e--;
		int cnt=0;
		for(int i=1;i<=M;i++)
		{
			for(int i=0;i<N;i++) visited[i]=false;
			dfs(s,i);
			cnt+=visited[e];
		}
		printf("%d\n",cnt);
	}
}