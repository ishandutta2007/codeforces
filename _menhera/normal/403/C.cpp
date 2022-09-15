#include<cstdio>
#define MAXN 2010
int N;
int arr[MAXN][MAXN];
bool visit[MAXN];
void dfs(int a)
{
	if(visit[a])
		return;
	visit[a]=true;
	for(int i=0;i<N;i++)
		if(!visit[i] && arr[a][i]!=0) dfs(i);
}
void dfs2(int a)
{
	if(visit[a])
		return;
	visit[a]=true;
	for(int i=0;i<N;i++)
		if(!visit[i] && arr[i][a]!=0) dfs2(i);
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&arr[i][j]);
	for(int j=0;j<N;j++)
		visit[j]=false;
	dfs(0);
	for(int j=0;j<N;j++)
		if(!visit[j])
		{
			puts("NO");
			return 0;
		}
	for(int j=0;j<N;j++)
		visit[j]=false;
	dfs2(0);
	for(int j=0;j<N;j++)
		if(!visit[j])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}