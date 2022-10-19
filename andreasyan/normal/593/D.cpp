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
ll d[N];
vector<int> a[N];
vector<int> b[N];

int dd[N];
int p0[N];
int p[N];
int ki[N];
int tin[N], tout[N], ti;

int fi(int x)
{
    if (x == 1)
        return 1;
    if (d[ki[p[x]]] > 1)
        return p[x];
    if (x == p[x])
        return p[x] = fi(p0[x]);
    return p[x] = fi(p[x]);
}

void dfs(int x)
{
    tin[x] = ++ti;
    p[x] = x;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p0[x])
            continue;
        ki[h] = b[x][i];
        p0[h] = x;
        dd[h] = dd[x] + 1;
        dfs(h);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        b[x].push_back(i);
        a[y].push_back(x);
        b[y].push_back(i);
        d[i] = z;
    }
    dfs(1);
    while (m--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int sx, sy;
            ll z;
            cin >> sx >> sy >> z;
            vector<ll> xx, yy;
            int x = sx, y = sy;
            while (1)
            {
                if (isp(x, sy) && isp(y, sx))
                    break;
                if (yy.size() + xx.size() > 60)
                    break;
                if (dd[x] > dd[y])
                {
                    x = fi(x);
                    if (isp(x, sy))
                        continue;
                    xx.push_back(d[ki[x]]);
                    x = p0[x];
                }
                else
                {
                    y = fi(y);
                    if (isp(y, sx))
                        continue;
                    yy.push_back(d[ki[y]]);
                    y = p0[y];
                }
            }
            reverse(all(yy));
            for (int i = 0; i < xx.size(); ++i)
                z /= xx[i];
            for (int i = 0; i < yy.size(); ++i)
                z /= yy[i];
            cout << z << endl;
        }
        else
        {
            int x;
            ll y;
            cin >> x >> y;
            d[x] = y;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}