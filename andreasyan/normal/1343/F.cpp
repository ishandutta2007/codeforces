#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 202;

int n;
set<int> a[N];

int ans[N];
set<int> s[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        a[i].clear();
    for (int i = 1; i < n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].insert(x);
        }
    }
    for (int p1 = 1; p1 <= n; ++p1)
    {
        for (int i = 1; i < n; ++i)
            s[i] = a[i];
        bool z = true;
        int u = p1;
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = u;
            for (int j = 1; j < n; ++j)
            {
                if (s[j].find(u) != s[j].end())
                    s[j].erase(u);
            }
            if (i == n)
            {
                for (int j = 1; j < n; ++j)
                {
                    if (!s[j].empty())
                        z = false;
                }
                break;
            }
            for (int j = 1; j < n; ++j)
            {
                if (s[j].size() == 1)
                {
                    u = *s[j].begin();
                    if (i + 1 - (int)a[j].size() < 0)
                    {
                        z = false;
                        break;
                    }
                    set<int> t;
                    for (int k = i + 1 - (int)a[j].size() + 1; k <= i; ++k)
                        t.insert(ans[k]);
                    t.insert(u);
                    if (t != a[j])
                    {
                        z = false;
                        break;
                    }
                    break;
                }
            }
            if (!z)
                break;
        }
        if (z)
        {
            for (int i = 1; i <= n; ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}