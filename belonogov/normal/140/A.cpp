#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const long double eps = 1e-7;
long double pi, a, b, c;

int main()
{
    int n, R, r;
    scanf("%d%d%d", &n, &R, &r);
    pi = 3.14159265358979323846;
    if (n == 1){
        if (R >= r)
            printf("YES");
        else
            printf("NO");
        return 0;
    }
    b = ((long double)r) / (R - r);
    if (b > 1){
        printf("NO");
        return 0;
    }
    c = asin(b);
    if (pi - c * n + eps >= 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}