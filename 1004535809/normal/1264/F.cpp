#include<cstdio>
int n,a,d;unsigned long long m=368131125,M=1e9,x=1.2e10;main(){scanf("%d%d%d",&n,&a,&d);printf("%llu %llu\n",m*a%M*x+1,m*d%M*x);}