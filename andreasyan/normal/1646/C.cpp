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

ll f[N];

void solv()
{
    int m;
    f[0] = 1;
    for (int i = 1; ; ++i)
    {
        f[i] = f[i - 1] * i;
        if (f[i] > 1000000000000)
        {
            m = i;
            break;
        }
    }

    ll n;
    cin >> n;

    int ans = 60;
    for (int x = 0; x < (1 << (m - 1)); ++x)
    {
        int yans = 0;
        ll u = n;
        for (int i = 0; i < m - 1; ++i)
        {
            if ((x & (1 << i)))
            {
                u -= f[i + 1];
                ++yans;
            }
        }

        if (u < 0)
            continue;

        for (int i = 0; i < 60; ++i)
        {
            if ((u & (1LL << i)))
            {
                if (i < 2 && (x & (1 << i)))
                    yans = 60;
                ++yans;
            }
        }
        ans = min(ans, yans);
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}