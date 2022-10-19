#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,n,t,a[200005],b[200005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int k0=0,sum=0,s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            a[i]%=2;
            sum+=a[i];
            s+=a[i];
            if(sum%2)
            {
                b[k0]=i+1;
                k0++;
                sum=0;
            }
        }
        if(k0>=k&&s%2==k%2)
        {
            printf("YES\n");
            for(i=0;i<k-1;i++)
            {
                printf("%d ",b[i]);
            }
            printf("%d\n",n);
        }
        else
            printf("NO\n");
    }
    return 0;
}
/*
3
5 3
7 18 3 14 1
5 4
1 2 3 4 5
6 2
1 2 8 4 10 2
YES
1 3 5
NO
NO
*/