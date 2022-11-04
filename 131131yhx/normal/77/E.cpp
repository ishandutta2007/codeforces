#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        printf("%.15lf\n", 1/(1/(a-b)+c*c*(a-b)/a/b));
    }
    return 0;
}