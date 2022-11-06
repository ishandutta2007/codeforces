#include <stdio.h>

int arr[2000];

int main()
{
    int n,s=0,d=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++)
        s+=arr[i];
    if(s==0)
    {
        printf("0");
        return 0;
    }
    for(i=0;i<n;i++)
        if(arr[i]==0&&arr[i+1]==1)
            d++;
    printf("%d",s+d-1);
    return 0;
}