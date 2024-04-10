#include <stdio.h>

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    
    printf("%s\n", n1 <= n2 ? "Second" : "First");
    
    return 0;
}