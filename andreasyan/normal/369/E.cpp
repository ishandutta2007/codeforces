#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, m = 1000000;
struct ban
{
    bool ty;
    int l, r;
    ban(){}
    ban(int l, int r, bool ty)
    {
        this->l = l;
        this->r = r;
        this->ty = ty;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.r < b.r)
        return true;
    if (a.r > b.r)
        return false;
    return a.ty > b.ty;
}

int n, q;
vector<ban> a;
vector<int> v[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return qry(tl, m, l, min(m, r), pos * 2)
         + qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

map<int, map<int, int> > u;
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        ban t;
        scanf("%d%d", &t.l, &t.r);
        t.ty = true;
        a.push_back(t);
    }
    for (int i = 0; i < q; ++i)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < q; ++i)
    {
        a.push_back(ban(1, v[i][0] - 1, false));
        for (int j = 1; j < v[i].size(); ++j)
        {
            int x = v[i][j - 1];
            int y = v[i][j];
            a.push_back(ban(x + 1, y - 1, false));
        }
        a.push_back(ban(v[i].back() + 1, m, false));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i)
    {
        bool ty = a[i].ty;
        int l = a[i].l, r = a[i].r;
        if (ty)
            ubd(1, m, l, 1);
        else
            u[l][r] = qry(1, m, l, r, 1);
    }
    for (int i = 0; i < q; ++i)
    {
        int ans = n;
        ans -= u[1][v[i][0] - 1];
        for (int j = 1; j < v[i].size(); ++j)
        {
            int x = v[i][j - 1];
            int y = v[i][j];
            ans -= u[x + 1][y - 1];
        }
        ans -= u[v[i].back() + 1][m];
        printf("%d\n", ans);
    }
    return 0;
}