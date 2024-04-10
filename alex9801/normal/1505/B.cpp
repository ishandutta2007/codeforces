#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int a;
    scanf("%d", &a);

    while(a >= 10)
    {
        int r = 0;
        while(a)
        {
            r += a % 10;
            a /= 10;
        }
        a = r;
    }

    printf("%d\n", a);
    return 0;
}