#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, INF = 1000000009;

int n;
int v[N], l[N], r[N];

bool rr[N];

set<int> s;
void dfs(int x, int ll, int rr)
{
    if (x == -1)
        return;
    if (ll <= v[x] && v[x] <= rr)
        s.insert(v[x]);
    dfs(l[x], ll, min(rr, v[x] - 1));
    dfs(r[x], max(ll, v[x] + 1), rr);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &v[i], &l[i], &r[i]);
        if (l[i] != -1)
            rr[l[i]] = true;
        if (r[i] != -1)
            rr[r[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!rr[i])
        {
            dfs(i, -INF, INF);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s.find(v[i]) == s.end())
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}