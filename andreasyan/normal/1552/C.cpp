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
const int N = 252;

int n, k;
int x[N], y[N];

bool c[N];
int u[N];

void solv()
{
    memset(c, false, sizeof c);

    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
        u[x[i]] = y[i];
        u[y[i]] = x[i];
        c[x[i]] = c[y[i]] = true;
    }

    int ans = 0;
    int yans = 0;
    for (int i = 1; i <= k; ++i)
    {
        int q1 = 0;
        int q2 = 0;
        for (int j = x[i]; j <= y[i]; ++j)
        {
            if (!c[j])
                ++q1;
        }
        for (int k = y[i]; k <= 2 * n; ++k)
        {
            if (!c[k])
                ++q2;
            else
            {
                if (x[i] < u[k] && u[k] < y[i])
                    ++yans;
            }
        }
        for (int k = 1; k <= x[i]; ++k)
        {
            if (!c[k])
                ++q2;
            else
            {
                if (x[i] < u[k] && u[k] < y[i])
                    ++yans;
            }
        }
        ans += min(q1, q2);
    }
    ans += (n - k) * (n - k - 1) / 2;
    ans += yans / 2;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}