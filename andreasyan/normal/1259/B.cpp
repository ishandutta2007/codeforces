#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

void solv()
{
    map<int, int> mp;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        int q = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            ++q;
        }
        mp[a[i]] = max(mp[a[i]], q);
    }
    int ans = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        ans += it->second;
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