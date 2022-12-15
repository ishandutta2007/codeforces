#include <stdio.h>

int n, m;
int arr[100000];

int main()
{
    scanf("%d %d", &n, &m);
    int a, b;
    int min = 987654321;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if(min > (b - a  +1)) min = (b - a + 1);
    }
    printf("%d\n", min);
    for(int i = 0; i < n; i++) {
        printf("%d ", i % min);
    }

    return 0;
}