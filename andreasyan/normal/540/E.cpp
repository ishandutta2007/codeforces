#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int qq;
map<int, int> mp;

int z;
map<int, int> u;

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
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (mp.find(x) == mp.end())
            mp[x] = x;
        if (mp.find(y) == mp.end())
            mp[y] = y;
        swap(mp[x], mp[y]);
    }
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        u[it->first] = ++z;
    }
    long long ans = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        ans += qry(1, z, u[it->second], z, 1);
        int ll = min(it->first, it->second);
        int rr = max(it->first, it->second);
        ans += (rr - ll + 1);
        ans -= (u[rr] - u[ll] + 1);
        ubd(1, z, u[it->second], 1);
    }
    printf("%lld\n", ans);
    return 0;
}