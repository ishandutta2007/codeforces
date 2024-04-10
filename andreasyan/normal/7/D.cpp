#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 10000007;

int n, m;
char a[N];
int z[N];

int ans[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    a[n++] = '#';
    for (int i = n - 2; i >= 0; --i)
        a[n++] = a[i];
    int r = 0, j = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - j]);
        }
        while (a[z[i]] == a[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
    n /= 2;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            ans[i] = 1;
            continue;
        }
        if (n * 2 - i + z[n * 2 - i] == n * 2 + 1)
        {
            if (i % 2 == 0)
                ans[i] = ans[i / 2 - 1] + 1;
            else
                ans[i] = ans[i / 2] + 1;
        }
    }
    int yans = 0;
    for (int i = 0; i < n; ++i)
        yans += ans[i];
    printf("%d\n", yans);
    return 0;
}