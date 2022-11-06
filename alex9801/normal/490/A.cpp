#include <stdio.h>

int arr[3][5000];
int cnt[3];

int main()
{
    int a,n,r,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        arr[a-1][cnt[a-1]++]=i+1;
    }
    r=cnt[1]<cnt[2]?cnt[1]:cnt[2];
    r=cnt[0]<r?cnt[0]:r;
    printf("%d\n",r);
    for(i=0;i<r;i++)
        printf("%d %d %d\n",arr[0][i],arr[1][i],arr[2][i]);
    return 0;
}