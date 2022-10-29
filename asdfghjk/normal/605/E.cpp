#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1005;
int n,i,j,k;
double p[N][N],f[N],w[N],s[N];
bool v[N];
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("0.0");
		return 0;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			scanf("%lf",p[i]+j);
			p[i][j]/=100.0;
		}
	for(i=1;i<=n;++i)
		w[i]=1.0;
	for(i=1;i<n;++i)
	{
		s[i]+=w[i]*p[i][n]*f[n];
		w[i]*=1.0-p[i][n];
	}
	v[n]=true;
	while(1)
	{
		j=0;
		for(i=1;i<=n;++i)
			if(!v[i])
			{
				if(w[i]==1.0)
					f[i]=1e50;
				else
					f[i]=(1.0+s[i])/(1-w[i]);
				if(j==0||f[i]<f[j])
					j=i;
			}
		if(j==1)
		{
			printf("%.12lf",f[j]);
			return 0;
		}
		v[j]=true;
		for(i=1;i<=n;++i)
			if(!v[i])
			{
				s[i]+=w[i]*p[i][j]*f[j];
				w[i]*=1.0-p[i][j];
			}
	}
	return 0;
}