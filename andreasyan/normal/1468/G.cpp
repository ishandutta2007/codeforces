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
#define double long double

int n, H;
int x[N], y[N];

double dist(double x1, double y1_, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1_ - y2) * (y1_ - y2));
}

pair<double, double> line0(double x1, double y1_, double x2, double y2)
{
    return m_p((y2 - y1_) / (x2 - x1), -x1 * (y2 - y1_) / (x2 - x1) + y1_);
}

void solv()
{
    cin >> n >> H;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    double ans = dist(x[n - 1], y[n - 1], x[n], y[n]);
    pair<double, double> u = line0(x[n - 1], y[n - 1], x[n], y[n] + H);
    for (int i = n - 2; i >= 1; --i)
    {
        pair<double, double> t = line0(x[i], y[i], x[i + 1], y[i + 1]);
        if (t.fi == u.fi)
        {
            if (u.se <= t.se + 0.000000001)
            {
                ans += dist(x[i], y[i], x[i + 1], y[i + 1]);
            }
        }
        else
        {
            double x0 = (t.se - u.se) / (u.fi - t.fi + 0.0);
            if (x[i] <= x0)
            {
                if (t.fi * (x0 + 10) + t.se < u.fi * (x0 + 10) + u.se)
                    ans += dist(x[i], y[i], x0, t.fi * x0 + t.se);
            }
        }

        t = line0(x[i], y[i], x[n], y[n] + H);
        if (t.se > u.se)
            u = t;
    }

    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}