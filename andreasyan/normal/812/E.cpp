#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int q[N];
int p[N];
vector<int> a[N];

int d[N];
void dfs(int x)
{
    d[x] = d[p[x]] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &q[i]);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &p[i]);
        a[p[i]].push_back(i);
    }
    dfs(1);
    int z;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].empty())
        {
            z = (d[i] % 2);
            break;
        }
    }
    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        if ((d[i] % 2) == z)
        {
            s ^= q[i];
        }
    }
    long long ans = 0;
    if (s == 0)
    {
        map<int, int> mp;
        int q1 = 0, q2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((d[i] % 2) == z)
            {
                ++q1;
            }
            else
            {
                ++q2;
                mp[q[i]]++;
            }
        }
        ans += (q1 * 1LL * (q1 - 1)) / 2;
        ans += (q2 * 1LL * (q2 - 1)) / 2;
        for (int i = 1; i <= n; ++i)
        {
            if ((d[i] % 2) == z)
            {
                ans += mp[q[i]];
            }
        }
    }
    else
    {
        map<int, int> mp;
        for (int i = 1; i <= n; ++i)
        {
            if ((d[i] % 2) != z)
            {
                mp[(s ^ q[i])]++;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if ((d[i] % 2) == z)
            {
                ans += mp[q[i]];
            }
        }
    }
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}