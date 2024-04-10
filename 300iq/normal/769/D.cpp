#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (1 << 14);
vector <int> cur;
int cnt[M];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ll ans = 0;
    int n, k, x;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < M; i++)
    {
        if (__builtin_popcount(i) == k)
        {
            cur.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        for (auto c : cur)
        {
            ans += cnt[x ^ c];
        }
        cnt[x]++;
    }
    printf("%lld\n", ans);
}