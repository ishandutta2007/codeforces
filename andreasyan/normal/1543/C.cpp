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
#define double long double
const double EPS = 0.000000000001;

double c, m, p, v;

double ans;
void rec(double c, double m, double p, int q, double d)
{
    if (c < EPS)
        c = 0;
    if (m < EPS)
        m = 0;
    if (c > 0)
    {
        if (c > v)
        {
            if (m > 0)
                rec(c - v, m + v / 2, p + v / 2, q + 1, d * c);
            else
                rec(c - v, 0, p + v, q + 1, d * c);
        }
        else
        {
            if (m > 0)
                rec(0, m + c / 2, p + c / 2, q + 1, d * c);
            else
                rec(0, 0, p + c, q + 1, d * c);
        }
    }
    swap(m, c);
    if (c > 0)
    {
        if (c > v)
        {
            if (m > 0)
                rec(c - v, m + v / 2, p + v / 2, q + 1, d * c);
            else
                rec(c - v, 0, p + v, q + 1, d * c);
        }
        else
        {
            if (m > 0)
                rec(0, m + c / 2, p + c / 2, q + 1, d * c);
            else
                rec(0, 0, p + c, q + 1, d * c);
        }
    }
    if (p > 0)
    {
        ans += d * p * q;
    }
}

void solv()
{
    cin >> c >> m >> p >> v;
    ans = 0;
    rec(c, m, p, 1, 1);
    cout << ans << "\n";
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
    cout.precision(12);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}