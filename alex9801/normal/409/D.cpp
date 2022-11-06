#include <stdio.h>

bool arr[17]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",arr[a-1]);
    return 0;
}