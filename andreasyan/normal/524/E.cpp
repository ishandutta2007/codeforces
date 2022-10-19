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

int n, m, k, q;
int x[N], y[N];
int x1[N], y1_[N], x2[N], y2[N];

bool ans[N];

vector<int> vv[N], qq[N];

int t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solvv()
{
    memset(t, 0, sizeof t);
    for (int j = 1; j <= m; ++j)
    {
        vv[j].clear();
        qq[j].clear();
    }
    for (int i = 1; i <= k; ++i)
        vv[y[i]].push_back(i);
    for (int i = 1; i <= q; ++i)
        qq[y2[i]].push_back(i);
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 0; i < vv[j].size(); ++i)
        {
            int x = ::x[vv[j][i]];
            ubd(1, n, x, j, 1);
        }
        for (int i = 0; i < qq[j].size(); ++i)
        {
            int u = ::x1[qq[j][i]];
            int d = ::x2[qq[j][i]];
            int l = ::y1_[qq[j][i]];
            if (qry(1, n, u, d, 1) >= l)
                ans[qq[j][i]] = true;
        }
    }
}

void solv()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= q; ++i)
        scanf("%d%d%d%d", &x1[i], &y1_[i], &x2[i], &y2[i]);
    solvv();
    swap(n, m);
    for (int i = 1; i <= k; ++i)
        swap(x[i], y[i]);
    for (int i = 1; i <= q; ++i)
    {
        swap(x1[i], y1_[i]);
        swap(x2[i], y2[i]);
    }
    solvv();
    for (int i = 1; i <= q; ++i)
    {
        if (ans[i])
            printf("YES\n");
        else
            printf("NO\n");
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