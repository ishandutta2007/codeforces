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
const int N = 20;

int n, k;
double a[N];

double dp[(1 << N)];
double ans[N];

void solv()
{
    cin >> n >> k;
    int d = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
            ++d;
    }
    k = min(k, d);
    dp[0] = 1;
    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        double s = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q;
            else
                s += a[i];
        }
        if (q == k)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                {
                    ans[i] += dp[x];
                }
            }
        }
        if (q >= k)
            continue;
        if (s == 0)
            continue;
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                dp[(x | (1 << i))] += (dp[x] * a[i] / s);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}