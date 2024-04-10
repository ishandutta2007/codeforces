#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if ((a[i] - a[i - 1]) == 1)
        {
            printf("2\n");
            return;
        }
    }
    printf("1\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}