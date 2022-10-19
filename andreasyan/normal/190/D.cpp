#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

map<int, vector<int> > mp;

int t[N * 4];

void ubd(int tl, int tr, int l, int r, int x, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos] = max(t[pos], x);
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, x, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, x, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, x, pos * 2);
        ubd(m + 1, tr, m + 1, r, x, pos * 2 + 1);
    }
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return max(t[pos], qry(tl, m, x, pos * 2));
    else
        return max(t[pos], qry(m + 1, tr, x,  pos * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        vector<int> v = it->second;
        for (int i = 0; i <= (int)v.size() - k; ++i)
        {
            int j = i + k - 1;
            /*if (j >= v.size())
            {
                cout << v.size() - k << ' ' << i << ' ' << j << endl;
                return 0;
            }*/
            ubd(1, n, v[j], n, v[i], 1);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += qry(1, n, i, 1);
    cout << ans << endl;
    return 0;
}