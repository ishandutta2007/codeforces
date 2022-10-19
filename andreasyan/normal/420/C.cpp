#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, p;
int q1[N];
map<int, map<int, int> > q;
vector<int> v[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return qry(tl, m, l, min(r, m), pos * 2) + qry(m + 1, tr, max(l, m + 1), r, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        q1[x]++;
        q1[y]++;
        q[max(x, y)][min(x, y)]++;
        v[max(x, y)].push_back(min(x, y));
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!v[i].empty())
            sort(v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!j || v[i][j] != v[i][j - 1])
            {
                if (q1[i] + q1[v[i][j]] - q[i][v[i][j]] >= p)
                    ++ans;
                ubd(0, n, q1[v[i][j]], -1, 1);
            }
        }
        ans += qry(0, n, max(0, p - q1[i]), n, 1);
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (!j || v[i][j] != v[i][j - 1])
                ubd(0, n, q1[v[i][j]], 1, 1);
        }
        ubd(0, n, q1[i], 1, 1);
    }
    cout << ans << endl;
    return 0;
}