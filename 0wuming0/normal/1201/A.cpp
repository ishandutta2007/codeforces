#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][5];
int main()
{
    int b,i,j,n,m,sum=0,t,mm;
    char c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        getchar();
        for(j=0;j<m;j++)
        {
            scanf("%c",&c);
            switch(c)
            {
                case'A':a[j][0]++;break;
                case'B':a[j][1]++;break;
                case'C':a[j][2]++;break;
                case'D':a[j][3]++;break;
                case'E':a[j][4]++;break;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&t);
        {
            mm=max(a[i][0],a[i][1]);
            mm=max(mm,a[i][2]);
            mm=max(mm,a[i][3]);
            mm=max(mm,a[i][4]);
            sum+=t*mm;
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*

*/