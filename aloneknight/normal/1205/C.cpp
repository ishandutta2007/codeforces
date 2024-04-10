#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=55;
int n,X1,Y1,X2,Y2,ans,a[N][N];vector<int>V;
inline int qry(int X1,int Y1,int X2,int Y2){printf("? %d %d %d %d\n",X1,Y1,X2,Y2);fflush(stdout);int x;scanf("%d",&x);return x^1;}
int main()
{
	scanf("%d",&n);
	a[1][1]=1;a[n][n]=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			if(i!=1)a[i][1]=a[i-2][1]^qry(i-2,1,i,1);
			for(int j=3;j<=n;j+=2)if(i!=n||j!=n)a[i][j]=a[i][j-2]^qry(i,j-2,i,j);
		}
		else for(int j=2;j<=n;j+=2)a[i][j]=a[i-1][j-1]^qry(i-1,j-1,i,j);
	}
	for(int i=4;i<=n;i+=2)a[1][i]=a[1][i-2]^qry(1,i-2,1,i);
	for(int i=3;i<=n;i+=2)a[2][i]=a[1][i-1]^qry(1,i-1,2,i);
	a[2][1]=a[2][3]^qry(2,1,2,3);
	for(int i=3;i<=n;i+=2)for(int j=2;j<=n;j+=2)a[i][j]=a[i-2][j]^qry(i-2,j,i,j);
	for(int i=4;i<=n;i+=2)for(int j=1;j<=n;j+=2)a[i][j]=a[i-2][j]^qry(i-2,j,i,j);
	for(int i=1;i<=n;i++)V.pb(a[i][1]);
	for(int i=2;i<=n;i++)V.pb(a[n][i]);
	for(int i=3;i<=n+n-2;i++)
	{
		if(V[i]^V[i-1]^V[i-2]^V[i-3])continue;
		X1=i-3<n?i-2:n;Y1=i-3<n?1:i-n-1;
		X2=i<n?i+1:n;Y2=i<n?1:i-n+2;break;
	}
	ans=a[X1][Y1]^a[X2][Y2]^qry(X1,Y1,X2,Y2);puts("!");
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d",(i+j)&1?(a[i][j]^ans):a[i][j]);puts("");}
	return 0;
}