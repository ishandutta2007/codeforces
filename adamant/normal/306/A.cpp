#include <cstdio>

main()
{  
int n,m;
scanf("%d%d",&n,&m);
while(n)
printf("%d ",n/m),n-=n/m--;
}