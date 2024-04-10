#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, INF = 1000000009;

int n, r;
int p[N], g[N];
vector<int> a[N];

int minu[N], maxu[N];

void dfs(int x)
{
    minu[x] = maxu[x] = g[x];
    if (!a[x].empty())
    {
        int l = a[x][0], r = a[x][1];
        if (g[l] > g[r])
        {
            swap(l, r);
            swap(a[x][0], a[x][1]);
        }
        dfs(l);
        minu[x] = minu[l];
        dfs(r);
        maxu[x] = maxu[r];
    }
}

int q;
long long yans;

vector<pair<int, double> > v;

void dfs1(int x, int ll)
{
    if (!a[x].empty())
    {
        int l = a[x][0], r = a[x][1];
        ++q;
        yans += minu[r];
        dfs1(l, ll);
        yans -= minu[r];
        yans += maxu[l];
        dfs1(r, g[x]);
        yans -= maxu[l];
        --q;
    }
    else
    {
        v.push_back(m_p(ll, (double)yans / q));
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i], &g[i]);
        if (p[i] == -1)
            r = i;
        else
            a[p[i]].push_back(i);
    }
    dfs(r);
    dfs1(r, -INF);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int gg;
        scanf("%d", &gg);
        int i = lower_bound(v.begin(), v.end(), m_p(gg, (double)0)) - v.begin();
        printf("%.12f\n", v[i - 1].second);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}