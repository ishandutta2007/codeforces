#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
char s[N], t[N];

int u[N][26];

void solv()
{
    scanf(" %s", s);
    scanf(" %s", t);
    n = strlen(s);
    m = strlen(t);
    for (int j = 0; j < 26; ++j)
        u[n][j] = n;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            u[i][j] = u[i + 1][j];
        u[i][s[i] - 'a'] = i;
    }
    for (int j = 0; j < m; ++j)
    {
        if (u[0][t[j] - 'a'] == n)
        {
            printf("-1\n");
            return;
        }
    }
    int ans = 1;
    int i = -1;
    for (int j = 0; j < m; ++j)
    {
        if (u[i + 1][t[j] - 'a'] == n)
        {
            ++ans;
            i = -1;
        }
        i = u[i + 1][t[j] - 'a'];
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}