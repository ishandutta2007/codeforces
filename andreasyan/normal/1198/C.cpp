#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<int> a[N];
pair<int, int> b[N];

int u[N];
bool c[N];

void solv()
{
    scanf("%d%d", &n, &m);
    n *= 3;
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].first, &b[i].second);
        a[b[i].first].push_back(b[i].second);
        a[b[i].second].push_back(b[i].first);
    }
    for (int ii = 0; ii < 10; ++ii)
    {
        for (int i = 1; i <= n; ++i)
        {
            c[i] = false;
            u[i] = i;
        }
        for (int i = n; i >= 1; --i)
            swap(u[i], u[(rnd() % i) + 1]);
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            int x = u[i];
            bool z = true;
            for (int j = 0; j < a[x].size(); ++j)
            {
                int h = a[x][j];
                if (c[h])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                v.push_back(x);
                c[x] = true;
                if (v.size() == n / 3)
                {
                    printf("IndSet\n");
                    for (int i = 0; i < v.size(); ++i)
                        printf("%d ", v[i]);
                    printf("\n");
                    return;
                }
            }
        }
    }
    for (int ii = 0; ii < 10; ++ii)
    {
        for (int i = 1; i <= n; ++i)
            c[i] = false;
        for (int i = 1; i <= m; ++i)
            u[i] = i;
        for (int i = m; i >= 1; --i)
            swap(u[i], u[(rnd() % i) + 1]);
        vector<int> v;
        for (int i = 1; i <= m; ++i)
        {
            int x = u[i];
            if (!c[b[x].first] && !c[b[x].second])
            {
                c[b[x].first] = c[b[x].second] = true;
                v.push_back(x);
                if (v.size() == n / 3)
                {
                    printf("Matching\n");
                    for (int i = 0; i < v.size(); ++i)
                        printf("%d ", v[i]);
                    printf("\n");
                    return;
                }
            }
        }
    }
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