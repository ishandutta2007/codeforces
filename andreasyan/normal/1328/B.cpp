#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
char a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        a[i] = 'a';
    a[n] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (k > (n - i - 1) * 1LL * (n - i - 2) / 2)
        {
            a[i] = 'b';
            k -= (n - i - 1) * 1LL * (n - i - 2) / 2;
            a[n - k] = 'b';
            break;
        }
    }
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
}