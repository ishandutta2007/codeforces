#include <bits/stdc++.h>
using namespace std;
#define N (202*1000)


int m,it[2][N],it_p[2];
vector <pair<int,int> > e[2][N],p[2];
char e_mark[N*3];

void dfs(int x,bool b,bool c=0)
{
	if(x==0)
	{
		b=1-b;
		while(it_p[b]<p[b].size())
		{
			if(!e_mark[p[b][it_p[b]].first])
				e_mark[p[b][it_p[b]].first]=((c)?'r':'b'),dfs(p[b][it_p[b]].second,b,1-c);
			it_p[b]++;
		}
		b=1-b;
		while(it_p[b]<p[b].size())
		{
			if(!e_mark[p[b][it_p[b]].first])
				e_mark[p[b][it_p[b]].first]=((c)?'r':'b'),dfs(p[b][it_p[b]].second,b,c);
			it_p[b]++;
		}
		return ;
	}
	while(it[b][x]<e[b][x].size())
	{
		if(!e_mark[e[b][x][it[b][x]].first])
			e_mark[e[b][x][it[b][x]].first]=((c)?'r':'b'),dfs(e[b][x][it[b][x]].second,1-b,1-c);
		it[b][x]++;
	}
		
}

int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int v,u;
		scanf("%d%d",&v,&u);
		e[0][v].push_back({i,u});
		e[1][u].push_back({i,v});
	}
	int m2=m+1;
	for(int i=1;i<N;i++)
	{
		if(((int)e[0][i].size())%2)
			p[0].push_back({m2,i}),e[0][i].push_back({m2++,0});
		if(((int)e[1][i].size())%2)
			p[1].push_back({m2,i}),e[1][i].push_back({m2++,0});
	}
	for(int i=1;i<N;i++)if(!it[0][i] && e[0][i].size())dfs(i,0);
	for(int i=1;i<=m;i++)printf("%c",e_mark[i]);
	return 0;
}