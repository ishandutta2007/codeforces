#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int main()
{
    scanf("%d %s", &n, a + 1);
    int sum = 0;
    int h = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
        if (a[i] != '?')
        {
            sum += (a[i] - '0');
        }
        else
        {
            ++h;
        }
    }
    for (int i = n / 2 + 1; i <= n; ++i)
    {
        if (a[i] != '?')
        {
            sum -= (a[i] - '0');
        }
        else
            --h;
    }
    for (int x = min(0, (h / 2) * 9); x <= max(0, (h / 2) * 9); ++x)
    {
        if (!(min(sum + x, sum + x + (h / 2) * 9) <= 0 && 0 <= max(sum + x, sum + x + (h / 2) * 9)))
        {
            printf("Monocarp\n");
            return 0;
        }
    }
    printf("Bicarp\n");
    return 0;
}