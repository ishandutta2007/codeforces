#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m;
int a[N], b[N];
int cb[N];
int ua[N], ub[N];

int ty[N];
int x[N], y[N];
int la[N], ra[N], lb[N], rb[N];

vector<int> v[N];

void subdx(int x, int y)
{
    while (x <= n)
    {
        v[x].push_back(y);
        x += (x & (-x));
    }
}

vector<int> t[N];

void ubdy(int x, int y, int z)
{
    y = lower_bound(all(v[x]), y) - v[x].begin() + 1;
    while (y <= v[x].size())
    {
        t[x][y] += z;
        y += (y & (-y));
    }
}

void ubdx(int x, int y, int z)
{
    while (x <= n)
    {
        ubdy(x, y, z);
        x += (x & (-x));
    }
}

int qryy(int x, int y)
{
    if (v[x].empty())
        return 0;
    y = upper_bound(all(v[x]), y) - v[x].begin();
    int ans = 0;
    while (y)
    {
        ans += t[x][y];
        y -= (y & (-y));
    }
    return ans;
}

int qryx(int x, int y)
{
    int ans = 0;
    while (x)
    {
        ans += qryy(x, y);
        x -= (x & (-x));
    }
    return ans;
}

int qry(int x1, int x2, int y1_, int y2)
{
    return qryx(x2, y2) - qryx(x2, y1_ - 1) - qryx(x1 - 1, y2) + qryx(x1 - 1, y1_ - 1);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ua[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        ub[b[i]] = i;
        cb[i] = b[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &ty[i]);
        if (ty[i] == 1)
            scanf("%d%d%d%d", &la[i], &ra[i], &lb[i], &rb[i]);
        else
            scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        subdx(i, ua[b[i]]);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (ty[i] == 2)
        {
            swap(b[x[i]], b[y[i]]);
            subdx(x[i], ua[b[x[i]]]);
            subdx(y[i], ua[b[y[i]]]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(all(v[i]));
        t[i].assign(v[i].size() + 4, 0);
    }
    for (int i = 1; i <= n; ++i)
        b[i] = cb[i];
    for (int i = 1; i <= n; ++i)
    {
        ubdx(i, ua[b[i]], 1);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (ty[i] == 1)
        {
            printf("%d\n", qry(lb[i], rb[i], la[i], ra[i]));
        }
        else
        {
            ubdx(x[i], ua[b[x[i]]], -1);
            ubdx(y[i], ua[b[y[i]]], -1);
            swap(b[x[i]], b[y[i]]);
            ubdx(x[i], ua[b[x[i]]], 1);
            ubdx(y[i], ua[b[y[i]]], 1);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}