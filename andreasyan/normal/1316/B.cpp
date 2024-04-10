#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
char a[N];

int kk;
char ans[N];

char b[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    kk = 1;
    for (int i = 1; i <= n; ++i)
        ans[i] = a[i];
    for (int k = 2; k <= n; ++k)
    {
        int j = 1;
        for (int i = k; i <= n; ++i)
        {
            b[j++] = a[i];
        }
        if (k % 2 != n % 2)
        {
            for (int i = 1; i < k; ++i)
                b[j++] = a[i];
        }
        else
        {
            for (int i = k - 1; i >= 1; --i)
                b[j++] = a[i];
        }
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i] != b[i])
            {
                z = (b[i] < ans[i]);
                break;
            }
        }
        if (z)
        {
            kk = k;
            for (int i = 1; i <= n; ++i)
                ans[i] = b[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%c", ans[i]);
    printf("\n");
    printf("%d\n", kk);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    /*n = 10;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
            a[i] = i + 'a' - 1;
        for (int l = 1; l <= n - k + 1; ++l)
        {
            int r = l + k - 1;
            reverse(a + l, a + r + 1);
        }
        for (int i = 1; i <= n; ++i)
            printf("%c", a[i]);
        printf("\n");
    }
    return 0;*/
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}