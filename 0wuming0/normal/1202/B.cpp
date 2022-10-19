#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int x,y,i,j,t,p;
    int a[10][10][10][10];
    for(x=0;x<10;x++)for(y=0;y<10;y++)
    {
        for(i=0;i<10;i++)for(j=0;j<10;j++)
        {
            if((i+x)%10==j||(i+y)%10==j)
            {
                a[x][y][i][j]=1;
            }
            else
            {
                    a[x][y][i][j]=100000;
            }
        }
        for(p=0;p<10;p++)for(i=0;i<10;i++)for(j=0;j<10;j++)for(t=0;t<10;t++)
        {
            if(a[x][y][i][t]<1000&&a[x][y][t][j]<1000)
                a[x][y][i][j]=min(a[x][y][i][t]+a[x][y][t][j],a[x][y][i][j]);
        }
        for(i=0;i<10;i++)for(j=0;j<10;j++)
        {
            if(a[x][y][i][j]==100000)
            {
                a[x][y][i][j]=-1;
            }
        }
    }//int i1,j1;for(i1=0;i1<10;i1++){for(j1=0;j1<10;j1++)printf("%d\t",a[2][3][i1][j1]);putchar(10);}
    int b[10][10]={0};
    char c,d;
    c=getchar()-'0';
    int m=0;
    if(c!=0)b[0][c]++;
    while(1)
    {
        if(scanf("%c",&d)==-1)break;
        if(d==' '||d==10)break;
        d-='0';
        b[c][d]++;
        c=d;
        m++;
    }//int i1,j1;for(i1=0;i1<10;i1++){for(j1=0;j1<10;j1++)printf("%d\t",b[i1][j1]);putchar(10);}
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            int sum=0;int flag=0;
            for(x=0;x<10;x++)for(y=0;y<10;y++)
            {
                sum+=a[i][j][x][y]*b[x][y];
                if(a[i][j][x][y]==-1&&b[x][y]!=0)flag=1;
            }
            if(flag)printf("-1 ");
            else printf("%d ",sum-m);
        }
        putchar(10);
    }
    return 0;
}
/*
0840
*/