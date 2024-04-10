#include<bits/stdc++.h>
#define eps 1e-15
using namespace std;
int n,i0=0,i1=1;
double c,p;
double q[2][10002],f[2][10002];
int main()
{
	scanf("%d%lf",&n,&c),c/=1000000;
	for(int i=0;i<=n;++i)scanf("%lf",&q[0][i]),q[0][i]/=1000000;
	for(int i=n-1;~i;--i,i0^=1,i1^=1)
		for(int j=0;j<=i;++j)
		{
			q[i1][j]=q[i0][j]/(i+1)*(i+1-j)+q[i0][j+1]/(i+1)*(j+1);
    		if(q[i1][j]<eps)continue;
			p=q[i0][j+1]/(i+1)*(j+1)/q[i1][j],f[i1][j]=max(0.0,p*(f[i0][j+1]+1)+(1-p)*f[i0][j]-c);
		}
	return 0&printf("%.10lf",f[i0][0]);
}