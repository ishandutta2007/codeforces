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

int n, m;

long double solv0(int n, int m, bool z)
{
    if (!z)
    {
        cout << "? " << m * 2 + 1 << endl;
        cout << "0 0" << endl;
        for (int j = 1; j <= m; ++j)
        {
            cout << n << ' ' << j << endl;
            if (j < m)
                cout << "0.000000000000001 " << j << endl;
            else
                cout << "0 " << j << endl;
        }
    }
    else
    {
        cout << "? " << m * 2 + 1 << endl;
        cout << "0 0" << endl;
        for (int j = 1; j <= m; ++j)
        {
            cout << j << ' ' << n << endl;
            if (j < m)
                cout << j << " 0.000000000000001" << endl;
            else
                cout << j << " 0" << endl;
        }
    }

    long double s0;
    cin >> s0;

    long double l = 0, r = n - 1;
    long double y0 = n - 1;
    for (int ii = 0; ii < 1000; ++ii)
    {
        long double y = (l + r) / 2;
        long double x1 = y / n;
        long double x2 = (y + 1) / n;
        long double s = ((1 - x1) + (1 - x2)) / 2;
        if (s <= s0)
        {
            y0 = y;
            r = y;
        }
        else
        {
            l = y;
        }
    }

    return y0;
}

void solv()
{
    cin >> n >> m;

    long double x = solv0(n, m, false);
    long double y = solv0(m, n, true);

    cout << "! " << x << ' ' << y << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}