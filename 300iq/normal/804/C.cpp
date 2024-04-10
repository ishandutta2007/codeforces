/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 7;

int ans[N];
int he[N];
int res[N];
vector <int> g[N];
vector <int> a[N];
vector <int> lul[N];

void dfs(int v, int pr, int h)
{
    he[v] = h;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v, h + 1);
        }
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
    for (int i = 1; i <= m; i++)
    {
        ans[i] = 1;
        res[i] = 1e9;
    }
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        while (s--)
        {
            int x;
            scanf("%d", &x);
            lul[i].push_back(x);
        }
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (auto c : lul[i])
        {
            res[c] = min(res[c], he[i + 1]);
        }
    }
    sort(a.begin(), a.end(), [] (int a, int b)
    {
        return he[a] < he[b];
    });
    int lfl = 1;
    for (int i : a)
    {
        vector <int> lel;
        int cnt = 0;
        set <int> s;
        for (auto c : lul[i - 1])
        {
            if (res[c] == he[i])
            {
                lel.push_back(c);
            }
            else
            {
                s.insert(ans[c]);
            }
        }
        int sz = 1;
        for (auto c : lel)
        {
            while (s.count(sz))
            {
                sz++;
            }
            s.insert(sz);
            ans[c] = sz;
            lfl = max(lfl, sz);
        }
    }
    printf("%d\n", lfl);
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", ans[i]);
    }
    puts("");
}