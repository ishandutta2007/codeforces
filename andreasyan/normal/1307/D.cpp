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

int n, m, k;
int u[N];
vector<int> a[N];

bool c[N];
void bfs(int s, int d[])
{
    memset(c, 0, sizeof c);
    queue<int> q;

    c[s] = true;
    d[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int d1[N], dn[N];

pair<int, int> b[N];
int s[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &u[i]);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bfs(1, d1);
    bfs(n, dn);

    for (int i = 1; i <= k; ++i)
    {
        b[i] = m_p(d1[u[i]], dn[u[i]]);
    }

    sort(b + 1, b + k + 1);
    for (int i = k; i >= 1; --i)
    {
        s[i] = max(s[i + 1], b[i].se);
    }

    int ans = 0;

    for (int i = k - 1; i >= 1; --i)
    {
        int l = i + 1, r = k;
        int u = k;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int x = b[i].fi + s[m];
            int y = b[i].se + b[m].fi;
            if (y < x)
            {
                l = m + 1;
            }
            else
            {
                u = m;
                r = m - 1;
            }
        }
        for (int m = max(i + 1, u - 5); m <= min(k, u + 5); ++m)
        {
            int x = b[i].fi + s[m] + 1;
            int y = b[i].se + b[m].fi + 1;
            ans = max(ans, min(d1[n], min(x, y)));
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