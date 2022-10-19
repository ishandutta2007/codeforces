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

struct ban
{
    int q[3];
    ban()
    {
        for (int i = 0; i < 3; ++i)
            q[i] = 0;
    }
    ban(char x)
    {
        for (int i = 0; i < 3; ++i)
            q[i] = 0;
        if (x == 'R')
            q[0] = 1;
        if (x == 'P')
            q[1] = 1;
        if (x == 'S')
            q[2] = 1;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    for (int i = 0; i < 3; ++i)
        res.q[i] = l.q[i] + r.q[i];
    return res;
}

int n, qq;
char a[N];

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, char y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int qrymin(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2].q[x])
        return qrymin(tl, m, x, pos * 2);
    return qrymin(m + 1, tr, x, pos * 2 + 1);
}

int qrymax(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2 + 1].q[x])
        return qrymax(m + 1, tr, x, pos * 2 + 1);
    return qrymax(tl, m, x, pos * 2);
}

int qry00(int r, int p, int s)
{
    if (t[1].q[r] == 0 || t[1].q[r] == n)
        return 0;
    if (t[1].q[s] == 0)
        return t[1].q[r];
    if (t[1].q[p] == 0)
        return 0;
    int left = qrymin(1, n, s, 1);
    int right = qrymax(1, n, s, 1);
    int ans = 0;
    ans += qry(1, n, 1, left - 1, 1).q[r];
    ans += qry(1, n, right + 1, n, 1).q[r];
    ans -= qry(1, n, 1, min(left, qrymin(1, n, p, 1)) - 1, 1).q[r];
    ans -= qry(1, n, max(right, qrymax(1, n, p, 1)) + 1, n, 1).q[r];
    return ans;
}

int qry0()
{
    int ans = n;
    ans -= qry00(0, 1, 2);
    ans -= qry00(1, 2, 0);
    ans -= qry00(2, 0, 1);
    return ans;
}

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    bil(1, n, 1);

    cout << qry0() << "\n";
    while (qq--)
    {
        int x;
        char y;
        cin >> x >> y;
        ubd(1, n, x, y, 1);
        cout << qry0() << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}