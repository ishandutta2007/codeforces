#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int q[12];
bool solv()
{
    memset(q, 0, sizeof q);
    scanf(" %s", a);
    n = strlen(a);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += (a[i] - '0');
        q[a[i] - '0']++;
    }
    if (sum % 3 != 0)
        return false;
    if (q[0] == 0)
        return 0;
    --q[0];
    bool z = false;
    for (int i = 0; i <= 9; i += 2)
    {
        if (q[i])
            z = true;
    }
    return z;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("red\n");
        else
            printf("cyan\n");
    }
    return 0;
}