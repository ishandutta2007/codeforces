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
const int N = 100005;

int xx, yy, zz, nn, m, qq;

int xl, xr, yl, yr, zl, zr;

int x[N], y[N], z[N];

int qx[N], qy[N], qz[N];
bool open[N], close[N];

int root[N * 4];

vector<int> ul, ur;

vector<int> maxu, minu;

int c;
int nc()
{
    ++c;
    maxu.push_back(-N);
    minu.push_back(N);
    ul.push_back(0);
    ur.push_back(0);
    return c;
}

void ubdy(int tl, int tr, int l, int r, pair<int, int> z, int pos)
{
    if (l > r)
        return;
    if (z.fi <= maxu[pos] && z.se >= minu[pos])
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] = max(maxu[pos], z.fi);
        minu[pos] = min(minu[pos], z.se);
        return;
    }
    int m = (tl + tr) / 2;
    if (!ul[pos])
        ul[pos] = nc();
    if (!ur[pos])
        ur[pos] = nc();
    ubdy(tl, m, l, min(m, r), z, ul[pos]);
    ubdy(m + 1, tr, max(m + 1, l), r, z, ur[pos]);
}

void ubdx(int tl, int tr, int l, int r, int ly, int ry, pair<int, int> z, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (!root[pos])
        {
            root[pos] = nc();
        }
        ubdy(1, yy, ly, ry, z, root[pos]);
        return;
    }
    int m = (tl + tr) / 2;
    ubdx(tl, m, l, min(m, r), ly, ry, z, pos * 2);
    ubdx(m + 1, tr, max(m + 1, l), r, ly, ry, z, pos * 2 + 1);
}

pair<int, int> qryy(int tl, int tr, int y, int pos)
{
    if (pos == 0)
        return m_p(-N, N);
    pair<int, int> z = m_p(maxu[pos], minu[pos]);
    if (tl == tr)
        return z;
    int m = (tl + tr) / 2;
    pair<int, int> tz;
    if (y <= m)
        tz = qryy(tl, m, y, ul[pos]);
    else
        tz = qryy(m + 1, tr, y, ur[pos]);
    return m_p(max(tz.fi, z.fi), min(tz.se, z.se));
}

pair<int, int> qryx(int tl, int tr, int x, int y, int pos)
{
    pair<int, int> z = qryy(1, yy, y, root[pos]);
    if (tl == tr)
        return z;
    int m = (tl + tr) / 2;
    pair<int, int> tz;
    if (x <= m)
        tz = qryx(tl, m, x, y, pos * 2);
    else
        tz = qryx(m + 1, tr, x, y, pos * 2 + 1);
    return m_p(max(tz.fi, z.fi), min(tz.se, z.se));
}

void solv()
{
    cin >> xx >> yy >> zz >> nn >> m >> qq;
    for (int i = 1; i <= nn; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (i == 1)
        {
            xl = xr = x;
            yl = yr = y;
            zl = zr = z;
            continue;
        }
        xl = min(xl, x);
        xr = max(xr, x);
        yl = min(yl, y);
        yr = max(yr, y);
        zl = min(zl, z);
        zr = max(zr, z);
    }

    for (int i = 1; i <= m; ++i)
    {
        cin >> x[i] >> y[i] >> z[i];
        if (xl <= x[i] && x[i] <= xr)
        {
            if (yl <= y[i] && y[i] <= yr)
            {
                if (zl <= z[i] && z[i] <= zr)
                {
                    cout << "INCORRECT\n";
                    return;
                }
            }
        }
    }
    cout << "CORRECT\n";

    maxu.push_back(-N);
    minu.push_back(N);
    ul.push_back(0);
    ur.push_back(0);
    for (int i = 1; i <= m; ++i)
    {
        int Lx, Rx;
        if (x[i] < xl)
        {
            Lx = 1;
            Rx = x[i];
        }
        else if (x[i] > xr)
        {
            Lx = x[i];
            Rx = xx;
        }
        else
        {
            Lx = 1;
            Rx = xx;
        }

        int Ly, Ry;
        if (y[i] < yl)
        {
            Ly = 1;
            Ry = y[i];
        }
        else if (y[i] > yr)
        {
            Ly = y[i];
            Ry = yy;
        }
        else
        {
            Ly = 1;
            Ry = yy;
        }

        if (z[i] < zl)
        {
            ubdx(1, xx, Lx, Rx, Ly, Ry, m_p(z[i], N), 1);
        }
        else if (z[i] > zr)
        {
            ubdx(1, xx, Lx, Rx, Ly, Ry, m_p(-N, z[i]), 1);
        }
        else
        {
            ubdx(1, xx, Lx, Rx, Ly, Ry, m_p(zz, 1), 1);
        }
    }

    for (int i = 1; i <= qq; ++i)
    {
        cin >> qx[i] >> qy[i] >> qz[i];

        close[i] = true;
        if (xl <= qx[i] && qx[i] <= xr)
        {
            if (yl <= qy[i] && qy[i] <= yr)
            {
                if (zl <= qz[i] && qz[i] <= zr)
                {
                    close[i] = false;
                }
            }
        }
        open[i] = true;

        pair<int, int> z = qryx(1, xx, qx[i], qy[i], 1);
        if (qz[i] <= z.fi || qz[i] >= z.se)
            open[i] = false;

        if (open[i] && close[i])
            cout << "UNKNOWN\n";
        else if (open[i])
            cout << "OPEN\n";
        else if (close[i])
            cout << "CLOSED\n";
        else
            assert(false);
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