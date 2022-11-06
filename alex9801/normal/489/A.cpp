#include <stdio.h>

int arr[3000];

int main()
{
    int n,r,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",n);
    for(i=0;i<n;i++)
    {
        r=i;
        for(j=i+1;j<n;j++)
            r=arr[j]<arr[r]?j:r;
        printf("%d %d\n",i,r);
        arr[r]=arr[i];
    }
    return 0;
}