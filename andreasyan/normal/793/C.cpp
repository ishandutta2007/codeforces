#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const long double EPS = 0.00000000000001, INF = 1000000009;

pair<long double, long double> hat(pair<long double, long double> a, pair<long double, long double> b)
{
    return m_p(max(a.first, b.first), min(a.second, b.second));
}

int n;
long double x1, y1, x2, y2;
long double rx[N], ry[N], vx[N], vy[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n; ++i)
        cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
    if (x1 == x2 || y1 == y2)
    {
        cout << "-1" << endl;
        return 0;
    }
    pair<long double, long double> ans = m_p(0, INF);
    for (int i = 1; i <= n; ++i)
    {
        if (x1 < rx[i] && rx[i] < x2)
        {
            if (vx[i] < 0)
            {
                ans = hat(ans, m_p(0, (rx[i] - x1) / (-vx[i])));
            }
            else if (vx[i] > 0)
            {
                ans = hat(ans, m_p(0, (x2 - rx[i]) / vx[i]));
            }
        }
        else if (rx[i] <= x1)
        {
            if (vx[i] <= 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            ans = hat(ans, m_p((x1 - rx[i]) / vx[i], (x2 - rx[i]) / vx[i]));
        }
        else
        {
            if (vx[i] >= 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            ans = hat(ans, m_p((rx[i] - x2) / (-vx[i]), (rx[i] - x1) / (-vx[i])));
        }
        swap(rx[i], ry[i]);
        swap(vx[i], vy[i]);
        swap(x1, y1);
        swap(x2, y2);
        if (x1 < rx[i] && rx[i] < x2)
        {
            if (vx[i] < 0)
            {
                ans = hat(ans, m_p(0, (rx[i] - x1) / (-vx[i])));
            }
            else if (vx[i] > 0)
            {
                ans = hat(ans, m_p(0, (x2 - rx[i]) / vx[i]));
            }
        }
        else if (rx[i] <= x1)
        {
            if (vx[i] <= 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            ans = hat(ans, m_p((x1 - rx[i]) / vx[i], (x2 - rx[i]) / vx[i]));
        }
        else
        {
            if (vx[i] >= 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            ans = hat(ans, m_p((rx[i] - x2) / (-vx[i]), (rx[i] - x1) / (-vx[i])));
        }
        swap(rx[i], ry[i]);
        swap(vx[i], vy[i]);
        swap(x1, y1);
        swap(x2, y2);
    }
    ans.first += EPS;
    ans.second -= EPS;
    if (ans.first <= ans.second)
        cout << ans.first << endl;
    else
        cout << "-1" << endl;
    return 0;
}