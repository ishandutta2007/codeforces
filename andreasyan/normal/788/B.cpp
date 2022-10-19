#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n, m;
vector<int> a[N];

bool cc[N];
int q = 0;
long long ans;

bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y)
        {
            ++q;
            cc[x] = true;
            continue;
        }
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ans += (q * 1LL * (m - 1));
    ans -= (q * 1LL * (q - 1)) / 2;
    for (int i = 1; i <= n; ++i)
        ans += ((int)a[i].size() * 1LL * ((int)a[i].size() - 1)) / 2;
    for (int i = 1; i <= n; ++i)
    {
        if ((!a[i].empty() || cc[i]))
        {
            dfs(i);
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i] && (!a[i].empty() || cc[i]))
        {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}