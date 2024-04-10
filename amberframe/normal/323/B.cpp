#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 1005;
const int inf = 1<<29;

int e[maxn][maxn],A[maxn],B[maxn],n;
void add(int n1,int n2)
{
	e[n2][n1]=e[n1][1]=e[1][n2]=1;
	for (int i=1;i<=A[0];i++)
		e[n1][A[i]]=e[A[i]][n2]=1;
	for (int i=1;i<=B[0];i++)
		e[n1][B[i]]=e[B[i]][n2]=1;
	A[++A[0]]=n1;B[++B[0]]=n2;
}

int d[maxn][maxn];
bool check(int n)
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		d[i][j]=e[i][j]?1:inf;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=j&&d[i][j]>2) return 0;
	return 1;
}

void dfs(int i,int j,int n)
{
	if (i>n) {
		if (check(n)) {
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					printf("%d ",e[i][j]);
				puts("");
			}
			exit(0);
		}
		return ;
	}
	if (j>n) {dfs(i+1,i+2,n);return ;}
	e[i][j]=1;e[j][i]=0;dfs(i,j+1,n);
	e[i][j]=0;e[j][i]=1;dfs(i,j+1,n);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("graph.in","r",stdin);
		freopen("graph.out","w",stdout);
	#endif
	
	scanf("%d",&n);
	if (n&1) {
		e[2][1]=e[1][3]=e[3][2]=1;
		A[A[0]=1]=2;B[B[0]=1]=3;
		for (int i=4;i<=n;i+=2) add(i,i+1);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				printf("%d ",e[i][j]);
			printf("\n");
		}
	}
	else {
		if (n<=4) puts("-1");
		else {
			e[1][2]=e[1][3]=e[1][4]=1;
			e[2][3]=e[2][4]=e[2][5]=1;
			e[3][4]=e[3][6]=1;
			e[4][5]=e[4][6]=1;
			e[5][1]=e[5][3]=e[5][6]=1;
			e[6][1]=e[6][2]=1;
			A[++A[0]]=5;A[++A[0]]=6;
			B[++B[0]]=2;B[++B[0]]=3;B[++B[0]]=4;
			for (int i=7;i<=n;i+=2) add(i,i+1);
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					printf("%d ",e[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}