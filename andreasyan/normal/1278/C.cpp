#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int p[N], s[N];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n + n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] == 2)
            a[i] = -1;
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }
    s[n + n + 1] = 0;
    for (int i = n + n; i >= n + 1; --i)
    {
        s[i] = s[i + 1] + a[i];
    }
    map<int, int> mp;
    for (int i = n + n + 1; i >= n + 1; --i)
        mp[s[i]] = i;
    int ans = n + n;
    for (int i = 0; i <= n; ++i)
    {
        if (mp.find(-p[i]) != mp.end())
        {
            ans = min(ans, n - i + mp[-p[i]] - n - 1);
        }
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