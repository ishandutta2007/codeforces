#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5003;

int n, aa, bb;
char a[N];

int m;
char b[N];
int z[N];
void clc()
{
    int r = 0, j = 0;
    for (int i = 1; i < m; ++i)
    {
        z[i] = 0;
        if (i <= r)
            z[i] = min(r - i + 1, z[i - j]);
        while (b[z[i]] == b[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
}

int p[N];
int dp[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &aa, &bb);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + aa;
        m = 0;
        for (int j = i; j >= 1; --j)
            b[m++] = a[j];
        clc();
        for (int j = 1; j <= i; ++j)
            p[j] = max(p[j - 1], z[i - j]);
        for (int j = i - 1; j >= 1; --j)
        {
            if (p[j] >= (i - j))
                dp[i] = min(dp[i], dp[j] + bb);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}