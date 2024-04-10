#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

bool z[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += (a[i] / 2);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 1)
        {
            if (sum < 0)
            {
                ++sum;
                z[i] = true;
            }
        }
        if (a[i] % 2 == -1)
        {
            if (sum > 0)
            {
                --sum;
                z[i] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!z[i])
            printf("%d\n", a[i] / 2);
        else
        {
            if (a[i] > 0)
                printf("%d\n", a[i] / 2 + 1);
            else
                printf("%d\n", a[i] / 2 - 1);
        }
    }
    return 0;
}