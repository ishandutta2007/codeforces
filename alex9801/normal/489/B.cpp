#include <stdio.h>
#include <algorithm>

int arr1[100];
int arr2[100];

int ab(int a)
{
    return a<0?-a:a;
}

int main()
{
    int n,m,p=0,q=0,c=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&arr2[i]);
    std::sort(arr1,arr1+n);
    std::sort(arr2,arr2+m);
    while(p<n&&q<m)
    {
        if(ab(arr1[p]-arr2[q])<=1)
        {
            c++;
            p++;
            q++;
        }
        else if(arr1[p]>arr2[q])
            q++;
        else
            p++;
    }
    printf("%d",c);
    return 0;
}