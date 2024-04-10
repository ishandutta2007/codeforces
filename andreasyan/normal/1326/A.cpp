#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n;
char a[N];

void solv()
{
    scanf("%d", &n);
    if (n == 1)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n - 1; ++i)
        a[i] = '7';
    a[n - 1] = '4';
    a[n] = 0;
    printf("%s\n", a);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
    long long x = 0;
    for (int i = 0; i < 15; ++i)
    {
        x = x * 10 + 7;
        long long y = (x * 10) + 4;
        if (y % 4 == 0 || y % 7 == 0)
            printf("WA");
    }
    return 0;
}