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
#define int long long

int gcd(int a, int b, int & x, int & y)
{
	if (a == 0)
    {
		x = 0; y = 1;
		return b;
	}
	int x1, y1_;
	int d = gcd(b % a, a, x1, y1_);
	x = y1_ - (b / a) * x1;
	y = x1;
	return d;
}

void go(int& n, int& m, int& x, int& y, int& vx, int& vy)
{
    int qx = 0;
    if (vx == -1)
        qx = x;
    else
        qx = n - x;
    int qy = 0;
    if (vy == -1)
        qy = y;
    else
        qy = m - y;

    x += min(qx, qy) * vx;
    y += min(qx, qy) * vy;
    if (qx < qy)
        vx *= -1;
    else
        vy *= -1;
}

pair<int, int> solv(int n, int m, int x, int y, int vx, int vy)
{
    if (vy == 0)
    {
        if (y == 0)
        {
            if (vx == -1)
            {
                return m_p(0, 0);
            }
            else
            {
                return m_p(n, 0);
            }
        }
        else if (y == m)
        {
            if (vx == -1)
            {
                return m_p(0, m);
            }
            else
            {
                return m_p(n, m);
            }
        }
        else
        {
            return m_p(-1, -1);
        }
    }
    if (vx == 0)
    {
        if (x == 0)
        {
            if (vy == -1)
            {
                return m_p(0, 0);
            }
            else
            {
                return m_p(0, m);
            }
        }
        else if (x == n)
        {
            if (vy == -1)
            {
                return m_p(n, 0);
            }
            else
            {
                return m_p(n, m);
            }
        }
        else
        {
            return m_p(-1, -1);
        }
    }

    int qx;
    if (vx == -1)
        qx = x;
    else
        qx = n - x;
    int qy;
    if (vy == -1)
        qy = y;
    else
        qy = m - y;

    int tx, ty;
    int g = gcd(n, m, tx, ty);
    if ((qy - qx) % g != 0)
        return m_p(-1, -1);
    tx *= (qy - qx) / g;
    ty *= (qy - qx) / g;
    ty *= -1;

    int qpx;
    if (tx < 0)
        qpx = (-tx) / (m / g) + !!((-tx) % (m / g));
    else
        qpx = (-tx) / (m / g);
    int qpy;
    if (ty < 0)
        qpy = (-ty) / (n / g) + !!((-ty) % (n / g));
    else
        qpy = (-ty) / (n / g);

    tx += max(qpx, qpy) * (m / g);
    ty += max(qpx, qpy) * (n / g);

    int ux, uy;
    if (vx == -1)
        ux = 0;
    else
        ux = n;
    if (vy == -1)
        uy = 0;
    else
        uy = m;
    if (tx % 2 == 1)
        ux = (n - ux);
    if (ty % 2 == 1)
        uy = (m - uy);

    return m_p(ux, uy);
}

/*pair<int, int> solv0(int n, int m, int x, int y, int vx, int vy)
{
    for (int ii = 0; ii < 1000; ++ii)
    {
        go(n, m, x, y, vx, vy);
        if (m_p(x, y) == m_p(0, 0) || m_p(x, y) == m_p(n, 0) || m_p(x, y) == m_p(0, m) || m_p(x, y) == m_p(n, m))
        {
            return m_p(x, y);
        }
    }
    return m_p(-1, -1);
}*/

int32_t main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int n = 1; n <= 10; ++n)
    {
        for (int m = 1; m <= 10; ++m)
        {
            for (int x = 0; x <= n; ++x)
            {
                for (int y = 0; y <= m; ++y)
                {
                    if (m_p(x, y) == m_p(0, 0) || m_p(x, y) == m_p(n, 0) || m_p(x, y) == m_p(0, m) || m_p(x, y) == m_p(n, m))
                        continue;
                    for (int vx = -1; vx <= 1; ++vx)
                    {
                        for (int vy = -1; vy <= 1; ++vy)
                        {
                            if (vx == 0 || vy == 0)
                                continue;
                            if (solv(n, m, x, y, vx, vy) != solv0(n, m, x, y, vx, vy))
                            {
                                cout << n << ' ' << m << ' ' << x << ' ' << y << ' ' << vx << ' ' << vy << "\n";
                                cout << solv(n, m, x, y, vx, vy).fi << ' ' << solv(n, m, x, y, vx, vy).se << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n, m, x, y, vx, vy;
        cin >> n >> m >> x >> y >> vx >> vy;
        pair<int, int> ans = solv(n, m, x, y, vx, vy);
        if (ans.fi == -1)
            cout << "-1\n";
        else
            cout << ans.fi << ' ' << ans.se << "\n";
    }
    return 0;
}