#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int b,i,j,n,m,sum=0,t,mm;
    scanf("%d",&n);
    int a[100002];
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(i=0;i<n;i++)
        sum+=a[i]%2;
    sum%=2;
    if(sum)
    {
        printf("NO\n");
        return 0;
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        a[n-1]-=a[i];
        if(a[n-1]<=0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
/*
6
1 2 3 4 6 18
*/