#include <stdio.h>

int arr[30000];

int main()
{
    int n,t,p=0,i;
    scanf("%d%d",&n,&t);
    for(i=0;i<n-1;i++)
        scanf("%d",&arr[i]);
    while(p<n)
    {
        if(p==t-1)
        {
            printf("YES");
            return 0;
        }
        if(p==n-1)
            break;
        p+=arr[p];
    }
    printf("NO");
    return 0;
}