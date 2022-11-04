#include<cstdio>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%.7lf", a / (b + c) * b);
    return 0;
}