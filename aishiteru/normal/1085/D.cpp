#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int n,s,rd[N];
int main(){
	scanf("%d%d",&n,&s);it i,tot=0,u,v;
	for(i=1;i<n;++i) scanf("%d%d",&u,&v),++rd[u],++rd[v];
	for(i=1;i<=n;++i) tot+=(rd[i]==1);
	printf("%.12lf",2.0*s/tot);
	return 0;
}