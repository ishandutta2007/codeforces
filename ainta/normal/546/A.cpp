#include<stdio.h>
int main()
{
    int k,n,w, r;
    scanf("%d%d%d",&k,&n,&w);
    r = w*(w+1)/2 *k - n;
    if(r<0)r=0;
    printf("%d\n",r);
}