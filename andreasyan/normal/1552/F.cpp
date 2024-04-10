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
const int N = 200005, M = 998244353;

int n;
int x[N], y[N], s[N];

int a[N];
int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> s[i];

    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i - 1;
        int u = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (x[m] > y[i])
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        if (u == -1)
            a[i] = (x[i] - y[i]) % M;
        else
        {
            a[i] = (x[i] - y[i]) % M;
            a[i] = (a[i] + p[i - 1] - p[u - 1]) % M;
        }
        a[i] = (a[i] + M) % M;
        p[i] = (p[i - 1] + a[i]) % M;
    }

    int ans = (x[n] + 1) % M;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i])
            ans = (ans + a[i]) % M;
    }

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}