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
const int N = 100005;

int n, m;
vector<pair<int, int> > a[N];
pair<pair<int, int>, int> b[N];

bool c[N];
int d[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].fi;
        if (c[h])
            continue;
        d[h] = (d[x] ^ a[x][i].se);
        dfs(h);
    }
}

const int k = 30;
int u[k];

void ave(int x)
{
    for (int i = k - 1; i >= 0; --i)
    {
        if ((x & (1 << i)))
        {
            if (!u[i])
            {
                u[i] = x;
                return;
            }
            else
            {
                x ^= u[i];
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
        b[i] = m_p(m_p(x, y), z);
    }
    dfs(1);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        x = b[i].fi.fi, y = b[i].fi.se, z = b[i].se;
        ave((z ^ d[x] ^ d[y]));
    }
    int ans = d[n];
    for (int i = k - 1; i >= 0; --i)
    {
        if ((ans & (1 << i)))
        {
            ans ^= u[i];
        }
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