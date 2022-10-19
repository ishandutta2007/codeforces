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
const int N = 300005;

int n;
int l[N], u[N], r[N];

int laz[N * 4];
int maxu[N * 4];
int maxi[N * 4];

void shi(int pos)
{
    maxu[pos * 2] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void bil(int tl, int tr, int pos)
{
    maxi[pos] = tl;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    if (maxu[pos * 2] > maxu[pos * 2 + 1])
    {
        maxu[pos] = maxu[pos * 2];
        maxi[pos] = maxi[pos * 2];
    }
    else
    {
        maxu[pos] = maxu[pos * 2 + 1];
        maxi[pos] = maxi[pos * 2 + 1];
    }
}

vector<int> v[N];

void solv()
{
    scanf("%d", &n);
    int z = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &l[i], &u[i], &r[i]);
        z = max(z, r[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        v[u[i]].push_back(i);
        v[r[i] + 1].push_back(-i);
    }
    int ans = 0;
    int ansr, ansl;
    bil(1, z, 1);
    for (int i = 1; i <= z; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] > 0)
                ubd(1, z, l[v[i][j]], u[v[i][j]], 1, 1);
            else
                ubd(1, z, l[-v[i][j]], u[-v[i][j]], -1, 1);
        }
        if (maxu[1] > ans)
        {
            ans = maxu[1];
            ansr = i;
            ansl = maxi[1];
        }
    }
    printf("%d\n", ans);
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (l[i] <= ansl && ansl <= u[i] && u[i] <= ansr && ansr <= r[i])
        {
            printf("%d ", i);
            ++q;
        }
    }
    assert(q == ans);
    printf("\n");
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