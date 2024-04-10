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
const int N = 200005, M = 998244353;

int n, qq;

int s[N * 4], laz1[N * 4], laz2[N * 4];

void ave(int tl, int tr, int pos, int x, int y)
{
    s[pos] = (s[pos] * 1LL * x) % M;
    s[pos] = (s[pos] + (tr - tl + 1) * 1LL * y) % M;

    laz1[pos] = (laz1[pos] * 1LL * x) % M;
    laz2[pos] = (laz2[pos] * 1LL * x + y) % M;
}

void shi(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    ave(tl, m, pos * 2, laz1[pos], laz2[pos]);
    ave(m + 1, tr, pos * 2 + 1, laz1[pos], laz2[pos]);

    laz1[pos] = 1;
    laz2[pos] = 0;
}

int z;
int ul[N * 100], ur[N * 100];
char t[N * 100];

void shi(int pos)
{
    if (t[pos] == 2)
        t[ul[pos]] = t[ur[pos]] = 2;
}

void ubd(int tl, int tr, int l, int r, int tpos, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (t[tpos] == 2)
        {
            ave(tl, tr, pos, 2, 0);
            return;
        }
        if (t[tpos] == 0)
        {
            ave(tl, tr, pos, 1, 1);
            t[tpos] = 2;
            return;
        }
    }
    shi(tl, tr, pos);

    if (!ul[tpos])
        ul[tpos] = ++z;
    if (!ur[tpos])
        ur[tpos] = ++z;
    shi(tpos);

    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), ul[tpos], pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, ur[tpos], pos * 2 + 1);

    s[pos] = (s[pos * 2] + s[pos * 2 + 1]) % M;
    if (t[ul[tpos]] == 2 && t[ur[tpos]] == 2)
        t[tpos] = 2;
    else if (t[ul[tpos]] == 0 && t[ur[tpos]] == 0)
        t[tpos] = 0;
    else
        t[tpos] = 1;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

void solv()
{
    for (int i = 0; i < N * 4; ++i)
        laz1[i] = 1;

    cin >> n >> qq;

    z = n;

    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;

            ubd(1, n, l, r, x, 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << qry(1, n, l, r, 1) << "\n";
        }
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