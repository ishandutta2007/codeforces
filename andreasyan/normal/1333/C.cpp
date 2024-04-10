#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    map<long long, int> mp;
    long long p = 0;
    mp[p] = 0;
    int maxu = 0;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        p += a[i];
        if (mp.find(p) != mp.end())
            maxu = max(maxu, mp[p] + 1);
        ans += (i - maxu);
        mp[p] = i;
    }
    printf("%lld\n", ans);
    return 0;
}