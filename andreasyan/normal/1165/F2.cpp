#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;

int n, m;
int q[N], cq[N];
int d[N], t[N];

vector<int> v[N];
int maxu[N];

bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        maxu[i] = 0;
        q[i] = cq[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        if (d[i] <= x)
        {
            maxu[t[i]] = max(maxu[t[i]], d[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (maxu[i])
        {
            v[maxu[i]].push_back(i);
        }
    }
    int p = 0;
    for (int i = 1; i <= x; ++i)
    {
        ++p;
        for (int j = 0; j < v[i].size(); ++j)
        {
            int t = v[i][j];
            if (q[t] <= p)
            {
                p -= q[t];
                q[t] = 0;
            }
            else
            {
                q[t] -= p;
                p = 0;
            }
        }
    }
    int qq = 0;
    for (int i = 1; i <= n; ++i)
        qq += q[i];
    for (int i = 1; i <= x; ++i)
        v[i].clear();
    return (p / 2 >= qq);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &q[i]);
        cq[i] = q[i];
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &d[i], &t[i]);
    int l = 1, r = N - 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}