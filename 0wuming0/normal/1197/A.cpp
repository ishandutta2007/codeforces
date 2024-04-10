#include"stdio.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int a[100005],n,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        printf("%d\n",min(a[n-2]-1,n-2)>0?min(a[n-2]-1,n-2):0);
    }
    return 0;
}