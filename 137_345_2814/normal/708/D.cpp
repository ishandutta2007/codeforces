#include<cstdio>
using namespace std;
#define N 450
double s[N][N],f[N];
int n,m,a,b,c,d,su;
void pivot(int n,int m,int x,int y)
{
	double tp=s[y][x];s[y][x]=-1;
	for(int i=1;i<=m+1;i++)s[y][i]/=-tp;
	for(int i=1;i<=n;i++)
	if(i!=y)
	{
		double tp=s[i][x];s[i][x]=0;
		for(int j=1;j<=m+1;j++)s[i][j]+=tp*s[y][j];
	}
	tp=f[x];f[x]=0;
	for(int j=1;j<=m+1;j++)f[j]+=tp*s[y][j];
}
double LP(int n,int m)
{
	while(1)
	{
		int sp=0;
		for(int i=1;i<=m;i++)if(f[i]>0)sp=i;
		if(sp==0)
		return f[m+1];
		int mn=1e9,as=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][sp]>=-1e-10)continue;
			double tp=s[i][m+1]/-s[i][sp];
			if(mn>tp)mn=tp,as=i;
		}
		if(as==0)return 1e100;
		pivot(n,m,sp,as);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);su+=d;
		f[i]=1;f[m+i]=f[m*2+i]=-1;
		s[a][i]++;s[a][m+i]++;s[n+a][i]--;s[n+a][m+i]--;
		s[b][i]--;s[b][m+i]--;s[n+b][i]++;s[n+b][m+i]++;
		s[n*2+i][i]=-1;s[n*2+i][m+i]=-1,s[n*2+i][m*2+i]=1;s[n*2+i][m*3+1]=c;
		s[n*2+m+i][i]=-1;s[n*2+m+i][m*3+1]=d;
	}
	for(int i=1;i<=m*3+1;i++)s[1][i]=s[n][i]=s[n+1][i]=s[n+n][i]=0;
	printf("%d\n",(int)(-LP(n*2+m*2,m*3)+su+0.1));
}