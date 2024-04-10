#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
int a[N], g[N];

bool c[N];

vector<int> v;

bool u[N];
bool stg(int x)
{
    for (int i = 0; i < v.size(); ++i)
    {
        u[i] = true;
        if (i - x >= 0)
        {
            if (!u[i - x])
                u[i] = false;
            if (v[i - x] != v[i])
                u[i] = false;
        }
        if (u[i] && i + x >= v.size())
            return true;
    }
    return false;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &g[i]);
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int ans = N;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        v.clear();
        int x = i;
        while (1)
        {
            v.push_back(g[x]);
            c[x] = true;
            if (c[a[x]])
                break;
            x = a[x];
        }
        for (int i = 1; i * i <= v.size(); ++i)
        {
            if (v.size() % i == 0)
            {
                if (stg(i))
                {
                    ans = min(ans, i);
                    break;
                }
                if (stg(v.size() / i))
                {
                    ans = min(ans, ((int)v.size() / i));
                }
            }
        }
    }
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        set<int> s;
        int j = 0;
        while (1)
        {
            if (s.find(j) != s.end())
                break;
            s.insert(j);
            j = (j + i) % n;
        }
        printf("%d\n", s.size());
    }
    return 0;
}