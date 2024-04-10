#include<bits/stdc++.h>
using namespace std;
int c[109];
double f[109][10009];
int main(){
	int n,i,j,k,m=0;
	double x,s=0;
	scanf("%d%lf",&n,&x),x/=2,f[0][0]=1;
	for(i=1;i<=n;++i)scanf("%d",c+i),m+=c[i];
	for(i=1;i<=n;++i)for(j=i;j;--j)for(k=c[i];k<=m;++k)f[j][k]+=f[j-1][k-c[i]]*j/(n-j+1);
	for(i=1;i<=n;++i)for(j=0;j<=m;++j)s+=f[i][j]*min((n*1.0/i+1)*x,j*1.0/i);
	printf("%.12lf",s);
	return 0;
}