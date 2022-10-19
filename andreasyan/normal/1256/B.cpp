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
    int i = 1;
    while (1)
    {
        if (i == n + 1)
            break;
        int minu = N;
        for (int j = i; j <= n; ++j)
            minu = min(minu, a[j]);
        for (int j = i; j <= n; ++j)
        {
            if (a[j] == minu)
            {
                for (int k = j - 1; k >= i; --k)
                    swap(a[k], a[k + 1]);
                if (a[i] < a[i - 1])
                    swap(a[i], a[i - 1]);
                i = j + 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
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
}