#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=405;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int c[30];
int n;
int f1[N][N][2][2];
int f2[2][N][N][3][3];
int op;
void Init ()
{
	f1[0][0][0][0]=1;
	for (int u=0;u<n;u++)
	for (int i=0;i<=u;i++)
	for (int a=0;a<=1;a++)
	for (int b=0;b<=1;b++) if (f1[u][i][a][b]!=0)
	{
		int x=f1[u][i][a][b];
		if (a==0&&u+1-2>=1)	f1[u+1][i][b][0]=add(f1[u+1][i][b][0],mul(24,x));
		else 				f1[u+1][i][b][0]=add(f1[u+1][i][b][0],mul(25,x));
		if (a!=1)   		f1[u+1][i+1][b][1]=add(f1[u+1][i+1][b][1],x);
	}
	///////////////////////////////////////////////
	op=0;
	f2[0][0][0][0][0]=1;
	for (int u=0;u<n;u++)
	{
	memset(f2[op^1],0,sizeof(f2[op^1]));
	for (int i=0;i<=u;i++)
	for (int j=0;j<=u;j++)
	for (int a=0;a<=2;a++)
	for (int b=0;b<=2;b++) if (f2[op][i][j][a][b]!=0)
	{
		int x=f2[op][i][j][a][b];
		
		if (a!=0||u+1-2<1)	f2[op^1][i][j][b][0]=add(f2[op^1][i][j][b][0],mul(x,24));
		else 				f2[op^1][i][j][b][0]=add(f2[op^1][i][j][b][0],mul(x,23));
		
		if (a!=1) f2[op^1][i+1][j][b][1]=add(f2[op^1][i+1][j][b][1],x);
		if (a!=2) f2[op^1][i][j+1][b][2]=add(f2[op^1][i][j+1][b][2],x);
	}
	op^=1;
	//printf("%d\n",op);
	}
	for (int u=n;u>=0;u--) 
	for (int i=n;i>=0;i--)
	for (int a=0;a<=2;a++)
	for (int b=0;b<=2;b++)
	f2[op][u][i][a][b]=add(f2[op][u][i][a][b],f2[op][u+1][i][a][b]);
	
	for (int u=n;u>=0;u--) 
	for (int i=n;i>=0;i--)
	for (int a=0;a<=2;a++)
	for (int b=0;b<=2;b++)
	f2[op][u][i][a][b]=add(f2[op][u][i][a][b],f2[op][u][i+1][a][b]);
}
int solve1()
{
	int cnt=0;
	for (int u=1;u<=26;u++)	
	{
		int sum=cnt;
		for (int i=c[u]+1;i<=n;i++)
		for (int a=0;a<=1;a++)
		for (int b=0;b<=1;b++)
		cnt=add(cnt,f1[n][i][a][b]);
	//	printf("%d %d\n",u,dec(cnt,sum));
	}
	/*for (int i=0;i<=n;i++)
	{
		int sum=0;
		for (int a=0;a<=1;a++)
		for (int b=0;b<=1;b++)
		sum=add(sum,f1[n][i][a][b]);
		printf("%d\n",sum);
	}*/
//	printf("cnt:%d\n",cnt);
	return cnt;
}
int solve2 ()
{
	int cnt=0;
	for (int u=1;u<=26;u++)
	for (int i=u+1;i<=26;i++)
	{
		int sum=cnt;
		for (int a=0;a<=2;a++)
		for (int b=0;b<=2;b++)
		cnt=add(cnt,f2[op][c[u]+1][c[i]+1][a][b]);
	//	printf("%d %d %d\n",u,i,dec(cnt,sum));
	}
//	printf("%d %d\n",f2[op][3][2][2][1],cnt);
	return cnt;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=26;u++) scanf("%d",&c[u]);
	Init();
	int ans;
	if (n==1) ans=26;
	else if (n==2) ans=26*26;
	else ans=mul(26*26,Pow(25,n-2));
//	printf("%d\n",ans);
	ans=dec(ans,solve1());
//	printf("%d\n",ans);
	ans=add(ans,solve2());
	printf("%d\n",ans);
	return 0;
}