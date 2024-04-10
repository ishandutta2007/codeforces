#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = N;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        if (mp.find(a[i]) != mp.end())
            ans = min(ans, i - mp[a[i]] + 1);
        mp[a[i]] = i;
    }
    if (ans == N)
        printf("-1\n");
    else
        printf("%d\n", ans);
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