#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
vector<int> a[N];

int ans;
vector<pair<int, int> > ansv;

void dfs0(int x, int p)
{
    vector<int> v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        v.push_back(a[x][i]);
    }
    a[x] = v;
}

void dfs(int x, int p, int s)
{
    int u = s;
    ansv.push_back(m_p(x, u));
    for (int i = 0; i < a[x].size(); ++i)
    {
        if (u == ans)
        {
            u = (s - 1) - (a[x].size() - i);
            ansv.push_back(m_p(x, u));
        }
        int h = a[x][i];
        dfs(h, x, u + 1);
        ++u;
        ansv.push_back(m_p(x, u));
    }
    if (s != 0 && u != s - 1)
    {
        u = s - 1;
        ansv.push_back(m_p(x, u));
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ans = a[1].size();
    for (int i = 2; i <= n; ++i)
        ans = max(ans, (int)a[i].size());
    dfs0(1, 1);
    dfs(1, 1, 0);
    printf("%d\n", ansv.size());
    for (int i = 0; i < ansv.size(); ++i)
        printf("%d %d\n", ansv[i].first, ansv[i].second);
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