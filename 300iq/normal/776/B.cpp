#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
vector <int> g[N];
int ans[N];
bool u[N];
bool kek[2];
int answ = 0;

void dfs(int v, int c)
{
    if (!kek[c])
    {
        answ++;
    }
    kek[c] = 1;
    if (u[v])
    {
        return;
    }
    u[v] = 1;
    ans[v] = c + 1;
    for (auto to : g[v])
    {
        dfs(to, c ^ 1);
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    n++;
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        vector <int> p;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                while (x % j == 0)
                {
                    x /= j;
                }
                p.push_back(j);
            }
        }
        if (x != 1)
        {
            p.push_back(x);
        }
        for (auto c : p)
        {
            if (c != i)
            {
                g[i].push_back(c);
                g[c].push_back(i);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!u[i])
        {
            dfs(i, 0);
        }
    }
    printf("%d\n", answ);
    for (int i = 2; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    puts("");
}