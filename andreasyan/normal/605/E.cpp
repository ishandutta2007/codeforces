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
const int N = 1003, INF = 1000000009;
#define double long double

int n;
double a[N][N];

bool c[N];
double ans[N];

double yans[N];
double mn[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            a[i][j] = x / (double)100;
        }
    }

    if (n == 1)
    {
        cout << "0\n";
    }

    c[n] = true;
    ans[n] = 0;

    for (int x = 1; x < n; ++x)
    {
        yans[x] = a[x][n] * ans[n];
        mn[x] = (1 - a[x][n]);
    }

    for (int ii = 0; ii < n - 1; ++ii)
    {
        double minu = INF;
        int minx;
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
                continue;
            double u = (1 + yans[x]) / (1 - mn[x]);
            if (u < minu)
            {
                minu = u;
                minx = x;
            }
        }

        c[minx] = true;
        ans[minx] = minu;
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
                continue;
            yans[x] += mn[x] * a[x][minx] * ans[minx];
            mn[x] *= (1 - a[x][minx]);
        }

        if (c[1])
        {
            cout << ans[1] << "\n";
            return;
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

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}