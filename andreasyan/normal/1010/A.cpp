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
const int N = 1003, M = 1000000009;

int n, m;
int a[N], b[N];

bool stg(double t)
{
    for (int i = 1; i <= n; ++i)
    {
        t -= (m + t) / a[i];
        if (t < 0)
            return false;
        t -= (m + t) / b[(i % n + 1)];
        if (t < 0)
            return false;
    }
    return true;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    if (!stg(M))
    {
        cout << "-1\n";
        return;
    }

    double l = 0, r = M;
    for (int ii = 0; ii < 200; ++ii)
    {
        double m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
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