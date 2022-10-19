#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005, nn = 200000;

int n, k;
int l[N], r[N];

set<pair<int, int> > t[N * 4];
void ubd(int tl, int tr, int l, int r, int rr, int ii, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].insert(m_p(rr, ii));
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), rr, ii, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, rr, ii, pos * 2 + 1);
}
void ubdh(int tl, int tr, int l, int r, int rr, int ii, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].erase(m_p(rr, ii));
        return;
    }
    int m = (tl + tr) / 2;
    ubdh(tl, m, l, min(m, r), rr, ii, pos * 2);
    ubdh(m + 1, tr, max(m + 1, l), r, rr, ii, pos * 2 + 1);
}
int qryq(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos].size();
    int m = (tl + tr) / 2;
    if (x <= m)
        return qryq(tl, m, x, pos * 2) + t[pos].size();
    return qryq(m + 1, tr, x, pos * 2 + 1) + t[pos].size();
}
pair<int, int> qrym(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        if (t[pos].empty())
            return m_p(0, 0);
        return (*(--t[pos].end()));
    }
    int m = (tl + tr) / 2;
    if (t[pos].empty())
    {
        if (x <= m)
            return qrym(tl, m, x, pos * 2);
        return qrym(m + 1, tr, x, pos * 2 + 1);
    }
    if (x <= m)
        return max(qrym(tl, m, x, pos * 2), (*(--t[pos].end())));
    return max(qrym(m + 1, tr, x, pos * 2 + 1), (*(--t[pos].end())));
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int ii = 1; ii <= n; ++ii)
    {
        scanf("%d%d", &l[ii], &r[ii]);
        ubd(1, nn, l[ii], r[ii], r[ii], ii, 1);
    }
    vector<int> ans;
    for (int x = 1; x <= nn; ++x)
    {
        int q = qryq(1, nn, x, 1);
        for (int j = 0; j < q - k; ++j)
        {
            int ii = qrym(1, nn, x, 1).second;
            ans.push_back(ii);
            ubdh(1, nn, l[ii], r[ii], r[ii], ii, 1);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}