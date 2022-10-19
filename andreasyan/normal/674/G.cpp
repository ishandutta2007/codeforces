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
const int N = 150005;

int n, m, p;
int a[N];
int k;

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.se < b.se;
}

vector<pair<int, int> > mer(const vector<pair<int, int> >& a, const vector<pair<int, int> >& b)
{
    vector<pair<int, int> > res;
    int ax = 0, bx = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            if (a[i].fi == b[j].fi)
            {
                res.push_back(m_p(a[i].fi, a[i].se + b[j].se));
                ax |= (1 << i);
                bx |= (1 << j);
                break;
            }
        }
    }
    for (int i = 0; i < a.size(); ++i)
    {
        if (!(ax & (1 << i)))
            res.push_back(a[i]);
    }
    for (int j = 0; j < b.size(); ++j)
    {
        if (!(bx & (1 << j)))
            res.push_back(b[j]);
    }
    sort(all(res), so);
    reverse(all(res));
    while (res.size() > k)
    {
        int q = res.back().se;
        res.pop_back();
        for (int i = 0; i < res.size(); ++i)
            res[i].se -= q;
    }
    return res;
}

vector<pair<int, int> > t[N * 4];
int laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].push_back(m_p(a[tl], 1));
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void shi(int tl, int tr, int pos)
{
    if (!laz[pos])
        return;
    int m = (tl + tr) / 2;
    t[pos * 2].clear();
    t[pos * 2].push_back(m_p(laz[pos], m - tl + 1));
    t[pos * 2 + 1].clear();
    t[pos * 2 + 1].push_back(m_p(laz[pos], tr - m));
    laz[pos * 2] = laz[pos];
    laz[pos * 2 + 1] = laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] = y;
        t[pos].clear();
        t[pos].push_back(m_p(y, r - l + 1));
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

vector<pair<int, int> > qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return vector<pair<int, int> >();
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    k = 100 / p;
    bil(1, n, 1);
    while (m--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l, r, y;
            scanf("%d%d%d", &l, &r, &y);
            ubd(1, n, l, r, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            vector<pair<int, int> > u = qry(1, n, l, r, 1);
            assert(u.size() <= k);
            printf("%d ", u.size());
            for (int i = 0; i < u.size(); ++i)
                printf("%d ", u[i].fi);
            printf("\n");
        }
    }
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}