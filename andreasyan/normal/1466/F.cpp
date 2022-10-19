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
const int N = 500005, M = 1000000007;

int n, m;
pair<int, int> b[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

bool c[N];
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    if (rnf() % 2)
        swap(x, y);
    p[x] = y;
    if (c[x])
        c[y] = true;
}

int ast[N];
int q[N];

void solv()
{
    vector<int> ans;

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        b[i].fi = b[i].se = -1;
        int q;
        scanf("%d", &q);
        if (q == 1)
            scanf("%d", &b[i].fi);
        else
            scanf("%d%d", &b[i].fi, &b[i].se);
    }

    for (int x = 1; x <= n; ++x)
        p[x] = x;

    for (int i = 0; i < m; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;
        if (y == -1)
        {
            if (c[fi(x)])
                continue;
            c[fi(x)] = true;
            ans.push_back(i + 1);
        }
        else
        {
            if (fi(x) != fi(y))
            {
                if (c[fi(x)] && c[fi(y)])
                    continue;
                kpc(x, y);
                ans.push_back(i + 1);
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        ++q[fi(x)];
    }

    int yans = 1;
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    for (int i = 1; i <= n; ++i)
    {
        if (!q[i])
            continue;
        if (c[i])
            yans = (yans * 1LL * ast[q[i]]) % M;
        else
            yans = (yans * 1LL * ast[q[i] - 1]) % M;
    }

    printf("%d %d\n", yans, sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}