#include<bits/stdc++.h>
using namespace std;
int N, M;
int r[101010];
int a[101010][2];
int tp[101010];
int color[101010];
vector<int> connREV[101010];
vector<int> conn[101010];
void NO()
{
	puts("NO");
	exit(0);
}
void solve(int i,int c)
{
	if(color[i]!=0 && color[i]!=c) NO();
	if(color[i]==c) return;
	color[i] = c;
	for(int j:conn[i])
		solve(j, c);
	for(int j:connREV[i])
		solve(j, 3-c);
	return ;
}
int main()
{
	
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; ++i) scanf("%d",r+i);
	for(int i=0; i<M; ++i)
	{
		int T;
		scanf("%d",&T);
		for(int j=0; j<T; ++j)
		{
			int x;
			scanf("%d",&x);
			a[x][tp[x]++] = i;
		}
	}
	for(int i=1; i<=N; ++i)
	{
		if(r[i]==1)
		{
			conn[a[i][0]].push_back(a[i][1]);
			conn[a[i][1]].push_back(a[i][0]);
		}
		else
		{
			connREV[a[i][0]].push_back(a[i][1]);
			connREV[a[i][1]].push_back(a[i][0]);
		}
	}
	for(int i=1; i<=N; ++i)
		if(!color[i])
			solve(i,1);
	puts("YES");
	return 0;
}