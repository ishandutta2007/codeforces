#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
vector<int> a[N];

long long ans;

int q2, q1;
int c[N];
void dfs(int x, int g)
{
    c[x] = g;
    if (g == 2)
        ++q2;
    else
        ++q1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
        {
            dfs(h, 3 - g);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (m == 0)
    {
        printf("3 %I64d\n", n * 1LL * (n - 1) * (n - 2) / 6);
        return;
    }
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        q2 = q1 = 0;
        dfs(i, 1);
        v.push_back(m_p(q2, q1));
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (c[y] == c[x])
            {
                printf("0 1\n");
                return;
            }
        }
    }
    bool z = false;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first > 1 || v[i].second > 1)
        {
            z = true;
            ans += (v[i].first * 1LL * (v[i].first - 1)) / 2;
            ans += (v[i].second * 1LL * (v[i].second - 1)) / 2;
        }
    }
    if (z)
    {
        printf("1 %I64d\n", ans);
        return;
    }
    q2 = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first == 1 && v[i].second == 1)
            ++q2;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first == 1 && v[i].second == 1)
            ans += (2 * (q2 - 1));
        else
            ans += q2;
    }
    printf("2 %I64d\n", ans);
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