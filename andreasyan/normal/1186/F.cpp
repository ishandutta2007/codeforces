#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n, m;
vector<int> a[N];
vector<int> b[N];

bool c[N];

vector<pair<int, int> > v;
void dfs(int x)
{
    while (!a[x].empty() && c[b[x].back()])
    {
        a[x].pop_back();
        b[x].pop_back();
    }
    if (a[x].empty())
        return;
    int h = a[x].back();
    c[b[x].back()] = true;
    v.push_back(m_p(x, h));
    dfs(h);
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
        b[x].push_back(i);
        b[y].push_back(i);
    }
    vector<vector<pair<int, int> > > vv;
    for (int i = 1; i <= n; ++i)
    {
        while (!a[i].empty() && c[b[i].back()])
        {
            a[i].pop_back();
            b[i].pop_back();
        }
        if (a[i].size() % 2 == 1)
        {
            v.clear();
            dfs(i);
            vv.push_back(v);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        while (1)
        {
            while (!a[i].empty() && c[b[i].back()])
            {
                a[i].pop_back();
                b[i].pop_back();
            }
            if (a[i].empty())
                break;
            v.clear();
            dfs(i);
            vv.push_back(v);
        }
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j < vv[i].size(); j += 2)
            ans.push_back(vv[i][j]);
        if (vv[i].size() % 2 == 0)
            ans.push_back(vv[i].back());
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}