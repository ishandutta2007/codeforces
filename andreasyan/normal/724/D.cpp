#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
char a[N];

char minu[N];
int r[N];

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
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return qry(tl, m, l, m, pos * 2) + qry(m + 1, tr, m + 1, r, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m;
    cin >> a;
    n = strlen(a);

    multiset<char> s;
    int rr[400];
    for (int i = 0; i < m; ++i)
    {
        s.insert(a[i]);
        rr[a[i]] = i;
    }
    minu[m - 1] = (*s.begin());
    r[m - 1] = rr[minu[m - 1]];

    char maxu = minu[m - 1];
    for (int i = m; i < n; ++i)
    {
        s.erase(s.find(a[i - m]));
        s.insert(a[i]);
        rr[a[i]] = i;

        minu[i] = (*s.begin());
        r[i] = rr[minu[i]];

        maxu = max(maxu, minu[i]);
    }

    vector<char> ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < maxu)
            ans.push_back(a[i]);
    }
    for (int i = m - 1; i < n; ++i)
    {
        if (minu[i] == maxu)
        {
            if (!qry(0, n - 1, i - m + 1, i, 1))
            {
                ubd(0, n - 1, r[i], 1);
                ans.push_back(maxu);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}