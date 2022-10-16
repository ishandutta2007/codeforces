#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
int x[1111111],y[1111111];
#include<vector>
std::vector<int>X[1111111],Y[1111111],v[1111111];
int col[1111111];
void dfs(int p,int c=1)
{
	col[p]=c;
	for(auto t:v[p])if(!col[t])dfs(t,-c);
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d%d",x+i,y+i),X[x[i]].push_back(i),Y[y[i]].push_back(i);
	for(ii=1;ii<=2e5;ii++)
	{
		for(i=1;i<X[ii].size();i+=2)
			v[X[ii][i]].push_back(X[ii][i-1]),v[X[ii][i-1]].push_back(X[ii][i]);
		for(i=1;i<Y[ii].size();i+=2)
			v[Y[ii][i]].push_back(Y[ii][i-1]),v[Y[ii][i-1]].push_back(Y[ii][i]);
	}for(i=1;i<=n;i++)
		if(!col[i])dfs(i);
	for(i=1;i<=n;i++)putchar((~col[i])?'r':'b');
}
/*
Just go for it.
*/