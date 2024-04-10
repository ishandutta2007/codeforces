#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = 1; i <= 10; i++) {
        int temp = a * i;
        if(temp % 10 == 0 || temp % 10 == b){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}