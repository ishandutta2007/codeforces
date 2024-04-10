#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,m;
double f[N][N];

double dp(int n,int m)
{
	if (f[n][m]>0) return f[n][m];
	if (!m) return 1;
	if (!n) return 1.0/(m+1);
	double k1=(1.0-dp(m-1,n))*m/(m+1)-1.0,k2=dp(m,n-1)-dp(m-1,n)*m/(m+1);
	double b1=1,b2=1.0-dp(m,n-1);
	double p=(b2-b1)/(k1-k2);
	return f[n][m]=1.0-p+p*(1.0-dp(m-1,n))*m/(m+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	double ans=dp(n,m);
	printf("%.10lf %.10lf\n",ans,1.0-ans);
	return 0;
}