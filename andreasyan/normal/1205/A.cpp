#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int ans[N];

int main()
{
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1, j = 1; i <= n; ++i, j += 2)
    {
        if (i % 2 == 1)
        {
            ans[i] = j;
            ans[i + n] = j + 1;
        }
        else
        {
            ans[i] = j + 1;
            ans[i + n] = j;
        }
    }
    for (int i = 1; i <= n + n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}