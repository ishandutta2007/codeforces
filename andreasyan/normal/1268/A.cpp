#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
char a[N];
char b[N];

bool mh(char a[], char b[])
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    for (int i = 0; i < n; ++i)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (i + k < n)
            b[i + k] = b[i];
    }
    if (mh(b, a))
    {
        printf("%d\n", n);
        printf("%s\n", b);
        return 0;
    }
    ++b[k - 1];
    for (int i = k - 1; i >= 0; --i)
    {
        if (b[i] > '9')
        {
            ++b[i - 1];
            b[i] = '0';
        }
        else
            break;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i + k < n)
            b[i + k] = b[i];
    }
    printf("%d\n", n);
    printf("%s\n", b);
    return 0;
}