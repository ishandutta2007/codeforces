#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 1000000007;

int n, m;
vector<pair<int, int> > b;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int k;
map<int, int> mp;

vector<int> a[N];

int c[N];
void dfs(int x)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
        {
            c[h] = 3 - c[x];
            dfs(h);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z)
            kpc(x, y);
        else
            b.push_back(m_p(x, y));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mp.find(fi(i)) == mp.end())
            mp[fi(i)] = ++k;
    }
    for (int i = 0; i < b.size(); ++i)
    {
        b[i].first = mp[fi(b[i].first)];
        b[i].second = mp[fi(b[i].second)];
        if (b[i].first == b[i].second)
        {
            printf("0\n");
            return;
        }
        a[b[i].first].push_back(b[i].second);
        a[b[i].second].push_back(b[i].first);
    }
    int q = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (!c[i])
        {
            c[i] = 1;
            ++q;
            dfs(i);
        }
    }
    for (int i = 0; i < b.size(); ++i)
    {
        if (c[b[i].first] == c[b[i].second])
        {
            printf("0\n");
            return;
        }
    }
    int ans = 1;
    for (int i = 0; i < q - 1; ++i)
    {
        ans = (ans * 2) % M;
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