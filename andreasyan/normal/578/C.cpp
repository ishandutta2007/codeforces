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

int n;
int a[N];

double p[N];
double stg(double x)
{
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i] - x;

    double ans = 0;

    double maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, -(p[i] - maxu));
        maxu = max(maxu, p[i]);
    }

    double minu = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, p[i] - minu);
        minu = min(minu, p[i]);
    }

    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    double l = -N, r = N;
    for (int ii = 0; ii < 100; ++ii)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (stg(m1) < stg(m2))
            r = m2;
        else
            l = m1;
    }

    cout << stg((l + r) / 2) << "\n";
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