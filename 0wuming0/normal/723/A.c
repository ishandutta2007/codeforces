#include<stdio.h>
int max(int x1,int x2,int x3)
{
    int max;
    if(x1<x2)max=x2;
    else max=x1;
    if(x3<max)max=max;
    else max=x3;
    return max;
}
int min(int x1,int x2,int x3)
{
    int min;
    if(x1>x2)min=x2;
    else min=x1;
    if(x3>min)min=min;
    else min=x3;
    return min;
}
int abs(int x)
{
    if(x<0)x=-x;
    else x=x;
}
int main()
{
    int x1,x2,x3,y,distance[100],min1,max1,d;
    scanf("%d %d %d",&x1,&x2,&x3);
    min1=min(x1,x2,x3);
    max1=max(x1,x2,x3);
    for(y=min1;y<=max1;y++)
    {
        distance[y]=abs(y-x1)+abs(y-x2)+abs(y-x3);
    }
    d=abs(min1-x1)+abs(min1-x2)+abs(min1-x3);
    for(y=min1;y<=max1;y++)
    {
        if(distance[y]<d)
            d=distance[y];
    }
    printf("%d", d);
    return 0;
}