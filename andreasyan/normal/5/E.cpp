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
const int N = 1000006;

int n;
int a[N];

int t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int qryl(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
    {
        if (t[pos] <= y)
            return -1;
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qryl(tl, m, l, min(m, r), y, pos * 2);
    if (u != -1)
        return u;
    return qryl(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qryr(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
    {
        if (t[pos] <= y)
            return -1;
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qryr(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    if (u != -1)
        return u;
    return qryr(tl, m, l, min(m, r), y, pos * 2);
}

void solv()
{
    scanf("%d", &n);
    int maxu = 0;
    map<int, vector<int> > v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        maxu = max(maxu, a[i]);
        v[a[i]].push_back(i);
    }
    bil(1, n, 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == maxu)
            continue;
        int u1 = qryl(1, n, i, n, a[i], 1);
        if (u1 == -1)
            u1 = qryl(1, n, 1, i, a[i], 1);
        int u2 = qryr(1, n, 1, i, a[i], 1);
        if (u2 == -1)
            u2 = qryr(1, n, i, n, a[i], 1);
        ans += 2;
        if (u1 == u2)
            --ans;
    }
    for (map<int, vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (sz(it->se) == 1)
            continue;
        if (it->fi == maxu)
        {
            ans += (sz(it->se) * 1LL * (sz(it->se) - 1)) / 2;
            continue;
        }
        vector<int> v;
        int q = 1;
        for (int i = 1; i < sz(it->se); ++i)
        {
            if (qry(1, n, it->se[i - 1], it->se[i], 1) <= it->fi)
                ++q;
            else
            {
                v.push_back(q);
                q = 1;
            }
        }
        v.push_back(q);
        for (int i = 0; i < v.size(); ++i)
        {
            ans += (v[i] * 1LL * (v[i] - 1)) / 2;
        }
        if (max(qry(1, n, it->se.back(), n, 1), qry(1, n, 1, it->se[0], 1)) <= it->fi)
            ans += v[0] * 1LL * v.back();
    }
    printf("%lld\n", ans);
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