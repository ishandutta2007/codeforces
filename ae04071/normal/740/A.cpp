#include <stdio.h>

long long arr[3];
int main()
{
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    if(a % 4 == 0){
        printf("0\n");
    }
    else if(a % 4 == 1) {
        long long r1 = d;
        long long r2 = b * 3;
        long long r3 = c + b;
        long long min = (r1 < r2) ? r1 : r2;
        min = (min < r3) ? min : r3;
        printf("%lld\n", min);
    }
    else if(a % 4 == 2 ){
        long long r1 = c;
        long long r2 = b * 2;
        long long r3 = d * 2;
        long long min = (r1 < r2) ? r1 : r2;
        min = (min < r3) ? min : r3;
        printf("%lld\n", min);
    }
    else {
        long long r1 = b;
        long long r2 = d * 3;
        long long r3 = d + c;
        long long min = (r1 < r2) ? r1 : r2;
        min = (min < r3) ? min : r3;
        printf("%lld\n", min);
    }

    return 0;
}