#include<cstdio>
double d[2009][2009];
bool f[2009],g[2009];
int main(){
	register int n,m,i,j,u=0,v=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		if(!f[i])f[i]=1,++u;
		if(!g[j])g[j]=1,++v;
	}
	u=n-u,v=n-v;
	for(i=1;i<=u;++i)d[i][0]=d[i-1][0]+n*1.0/i;
	for(i=1;i<=v;++i)d[0][i]=d[0][i-1]+n*1.0/i;
	for(i=1;i<=u;++i){
		for(j=1;j<=v;++j){
			d[i][j]=(d[i-1][j]*i*(n-j)+d[i][j-1]*(n-i)*j+d[i-1][j-1]*i*j+n*n)/(n*n-(n-i)*(n-j));
		}
	}
	printf("%.7lf",d[u][v]);
	return 0;
}