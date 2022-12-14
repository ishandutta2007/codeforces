#include <stdio.h>
#include <stdlib.h>
  int a[100001],b[100001],i,j,n,m,fl,l,r,t;
int main()
{   scanf("%d%d%d",&n,&l,&r);

    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<l-1;i++)if(a[i]!=b[i])fl=1;
    for(i=r;i<n;i++)if(a[i]!=b[i])fl=1;
    if(fl==1)printf("LIE\n"); else printf("TRUTH\n");
    return 0;
}