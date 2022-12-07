#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=(1<<28);
const int N=205;
int Ans=MAX;
int n;
char ss[5][N][N];
char t[N][N];
bool ok[5];
int ans[2][N][N];
bool check ()
{
	/*if (t[2][3]!=t[2][4])
	{
	for (int u=1;u<=2*n;u++)
	{
		for (int i=1;i<=2*n;i++)
			printf("%c",t[u][i]);
		printf("\n");
	}	
	system("pause");
	}*/
	int lalal=0;
	for (int u=1;u<=2*n;u++)
		for (int i=1;i<=2*n;i++)
			if (t[u][i]-'0'!=ans[0][u][i])
				lalal++;
	Ans=min(Ans,lalal);
	lalal=0;
	for (int u=1;u<=2*n;u++)
		for (int i=1;i<=2*n;i++)
			if (t[u][i]-'0'!=ans[1][u][i])
				lalal++;
	Ans=min(Ans,lalal);
}
void dfs (int x) 
{
	if (x>4)	{check();return ;}
	/*if (ok[1]==true&&ok[3]==true&&x==3)
	{
		for (int i=1;i<=4;i++) printf("%d ",ok[i]);
		printf("\n");
		printf("YES\n");
		for (int u=1;u<=2*n;u++)
	{
		for (int i=1;i<=2*n;i++)
			printf("%c",t[u][i]);
		printf("\n");
	}	
	system("pause");
	}*/
	int X,Y;
	if (x==1) {X=1;Y=1;}
	if (x==2) {X=1;Y=n+1;}
	if (x==3) {X=n+1;Y=1;}
	if (x==4) {X=n+1;Y=n+1;}
	for (int xx=1;xx<=4;xx++)
	{
		if (ok[xx]==true) continue;
		ok[xx]=true;
		for (int u=1;u<=n;u++)
			for (int i=1;i<=n;i++)
				t[X+u-1][Y+i-1]=ss[xx][u][i];
		dfs(x+1);
		ok[xx]=false;
	}
}
int main()
{
	memset(ok,false,sizeof(ok));
	scanf("%d",&n);
	ans[0][1][1]=0;ans[1][1][1]=1;
	for (int u=1;u<=2*n;u++)
		for (int i=1;i<=2*n;i++)
		{
			if (u==1&&i==1) continue;
			if (u!=1) {ans[0][u][i]=(ans[0][u-1][i]^1);ans[1][u][i]=(ans[1][u-1][i]^1);}
			else {ans[0][u][i]=(ans[0][u][i-1]^1);ans[1][u][i]=(ans[1][u][i-1]^1);}
		}
	/*for (int u=1;u<=2*n;u++)
	{
		for (int i=1;i<=2*n;i++)
		{
			printf("%d ",ans[0][u][i]);
		}
		printf("\n");
	}*/
	for (int u=1;u<=4;u++)
		for (int i=1;i<=n;i++)
			scanf("%s",ss[u][i]+1);
	dfs(1);
	printf("%d\n",Ans);
	return 0;
}