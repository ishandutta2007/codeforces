#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
int w[N];
int pr[N];
int sz[N];
vector <int> kek[N];

int get(int v)
{
    if (v == pr[v])
    {
        return v;
    }
    else
    {
        return get(pr[v]);
    }
}

int cl(int v)
{
    if (v == pr[v])
    {
        return 0;
    }
    else
    {
        return cl(pr[v]) ^ w[v];
    }
}

void uni(int u, int v, int c)
{
    int a = u, b = v;
    u = get(u), v = get(v);
    if (sz[u] > sz[v])
    {
        swap(a, b);
        swap(u, v);
    }
    pr[u] = v;
    sz[v] += sz[u];
    if (cl(a) != cl(b) ^ c)
    {
        w[u] = 1;
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
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> r(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &r[i]);
    }
    for (int i = 0; i < m; i++)
    {
        pr[i] = i;
        sz[i] = 1;
        int x;
        scanf("%d", &x);
        for (int cnt = 0; cnt < x; cnt++)
        {
            int j;
            scanf("%d", &j);
            j--;
            kek[j].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (r[i] == 1)
        {
            if (get(kek[i][0]) == get(kek[i][1]))
            {
                if (cl(kek[i][0]) != cl(kek[i][1]))
                {
                    puts("NO");
                    return 0;
                }
            }
            else
            {
                uni(kek[i][0], kek[i][1], 0);
            }
        }
        else
        {
            if (get(kek[i][0]) == get(kek[i][1]))
            {
                if (cl(kek[i][0]) == cl(kek[i][1]))
                {
                    puts("NO");
                    return 0;
                }
            }
            else
            {
                uni(kek[i][0], kek[i][1], 1);
            }
        }
    }
    puts("YES");
}