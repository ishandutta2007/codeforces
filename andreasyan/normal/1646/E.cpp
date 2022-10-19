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
const int N = 1000006;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int u[N];

int n, m;

int h[21];

void solv()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }

    cin >> n >> m;

    for (int g = 1; g <= 20; ++g)
    {
        for (int j = 1; j <= m; ++j)
        {
            bool z = false;
            for (int gg = g - 1; gg >= 1; --gg)
            {
                if ((g * j) % gg == 0)
                {
                    if ((g * j) / gg <= m)
                        z = true;
                    break;
                }
            }
            h[g] += z;
        }
    }

    ll ans = 1;
    for (int i = 2; i <= n; ++i)
    {
        ans += m;

        vector<int> v;
        vector<int> q;
        int x = i;
        while (x > 1)
        {
            if (v.empty() || u[x] != v.back())
            {
                v.push_back(u[x]);
                q.push_back(0);
            }
            x /= u[x];
            ++q.back();
        }

        int g = 0;
        for (int i = 0; i < sz(v); ++i)
            g = gcd(g, q[i]);

        ans -= h[g];
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