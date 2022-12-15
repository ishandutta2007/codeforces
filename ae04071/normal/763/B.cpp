#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a, b,c,d;
    printf("YES\n");
    for(int i=0;i<n;i++) {
        scanf("%d %d %d %d", &a, &b,&c,&d);
       	printf("%d\n", 2*(a&1)+(b&1)+1);
    }
    
    return 0;
}