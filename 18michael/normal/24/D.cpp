#include<cstdio>
#define R register
int n,m,u,v;
double t;
double f[1002][1002],Matrix[1002][1002];
inline void Gaussian()
{
	for(R int i=1;i<m;++i)
	{
		if(i>1)t=Matrix[i][i-1],Matrix[i][i-1]-=t*Matrix[i-1][i-1],Matrix[i][i]-=t*Matrix[i-1][i],Matrix[i][m+1]-=t*Matrix[i-1][m+1];
		t=Matrix[i][i],Matrix[i][i]/=t,Matrix[i][i+1]/=t,Matrix[i][m+1]/=t;
	}
	t=Matrix[m][m-1],Matrix[m][m-1]/=t,Matrix[m][m]/=t,Matrix[m][m+1]/=t;
	Matrix[m][m-1]-=Matrix[m-1][m-1],Matrix[m][m]-=Matrix[m-1][m],Matrix[m][m+1]-=Matrix[m-1][m+1];
	t=Matrix[m][m],Matrix[m][m]/=t,Matrix[m][m+1]/=t;
	for(R int i=m-1;i;--i)t=Matrix[i][i+1],Matrix[i][i+1]-=t*Matrix[i+1][i+1],Matrix[i][m+1]-=t*Matrix[i+1][m+1];
}
inline void solve(int x)
{
	if(x==n)return ;
	solve(x+1);
	for(R int i=1;i<=m;++i)
		for(R int j=1;j<=m;++j)
			Matrix[i][j]=0;
	Matrix[1][1]=2,Matrix[1][2]=-1,Matrix[1][m+1]=3+f[x+1][1];
	Matrix[m][m]=2,Matrix[m][m-1]=-1,Matrix[m][m+1]=3+f[x+1][m];
	for(R int i=2;i<m;++i)Matrix[i][i]=3,Matrix[i][i-1]=-1,Matrix[i][i+1]=-1,Matrix[i][m+1]=4+f[x+1][i];
	Gaussian();
	for(R int i=1;i<=m;++i)f[x][i]=Matrix[i][m+1];
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&u,&v);
	if(m==1)printf("%.10lf",2.0*(n-u));
	else solve(u),printf("%.10lf",f[u][v]);
	return 0;
}