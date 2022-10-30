

#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a[2],b[2],c,i;
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        a[c%2]++;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&c);
        b[c%2]++;
    }
    printf("%d",min(a[0],b[1])+min(a[1],b[0]));
}