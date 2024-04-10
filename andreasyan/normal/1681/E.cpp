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
const ll INF = 1000000009000000009;

struct ban0
{
    int x, y;
};

int n;
ban0 a[N], b[N];

struct ban
{
    ll d[2][2];
    ban()
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                d[i][j] = INF;
            }
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                res.d[i][j] = min(res.d[i][j], l.d[i][k] + r.d[k][j]);
            }
        }
    }
    return res;
}

ban t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].d[0][0] = 1 + abs(a[tl].x + 1 - a[tr + 1].x) + abs(a[tl].y - a[tr + 1].y);
        t[pos].d[0][1] = 1 + abs(a[tl].x + 1 - b[tr + 1].x) + abs(a[tl].y - b[tr + 1].y);
        t[pos].d[1][0] = 1 + abs(b[tl].x - a[tr + 1].x) + abs(b[tl].y + 1 - a[tr + 1].y);
        t[pos].d[1][1] = 1 + abs(b[tl].x - b[tr + 1].x) + abs(b[tl].y + 1 - b[tr + 1].y);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    assert(l <= r);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

void solv()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;

    a[n] = a[n - 1];
    a[n].x++;
    b[n] = b[n - 1];
    b[n].y++;

    bil(1, n - 1, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x1, y1_, x2, y2;
        cin >> x1 >> y1_ >> x2 >> y2;

        if (max(x1, y1_) > max(x2, y2))
        {
            swap(x1, x2);
            swap(y1_, y2);
        }

        if (max(x1, y1_) == max(x2, y2))
        {
            cout << abs(x1 - x2) + abs(y1_ - y2) << "\n";
            continue;
        }

        ban u;
        if (max(x1, y1_) + 1 != max(x2, y2))
            u = qry(1, n - 1, max(x1, y1_), max(x2, y2) - 2, 1);
        else
        {
            u.d[0][0] = 0;
            u.d[1][1] = 0;
        }

        ll ans = INF;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                ll yans = u.d[i][j];
                if (i == 0)
                    yans += abs(x1 - a[max(x1, y1_)].x) + abs(y1_ - a[max(x1, y1_)].y);
                else
                    yans += abs(x1 - b[max(x1, y1_)].x) + abs(y1_ - b[max(x1, y1_)].y);

                if (j == 0)
                    yans += 1 + abs(a[max(x2, y2) - 1].x + 1 - x2) + abs(a[max(x2, y2) - 1].y - y2);
                else
                    yans += 1 + abs(b[max(x2, y2) - 1].x - x2) + abs(b[max(x2, y2) - 1].y + 1 - y2);

                ans = min(ans, yans);
            }
        }

        cout << ans << "\n";
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