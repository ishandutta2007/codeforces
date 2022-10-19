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
const int N = 2000006;
const ll INF = 1000000009000000009;

int n, k;
int a[N];

int m;

int max1[N], max2[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    m = 0;
    while ((1 << m) <= n)
        ++m;

    for (int x = 0; x < (1 << m); ++x)
        max1[x] = max2[x] = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i >= max1[a[i]])
        {
            max2[a[i]] = max1[a[i]];
            max1[a[i]] = i;
        }
        else if (i >= max2[a[i]])
            max2[a[i]] = i;
    }

    ll ans = -INF;
    for (int x = 0; x < (1 << m); ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
            {
                int y = (x ^ (1 << i));
                int u = max1[y];
                if (u != max1[x] && u != max2[x])
                {
                    if (u >= max1[x])
                    {
                        max2[x] = max1[x];
                        max1[x] = u;
                    }
                    else if (u >= max2[x])
                    {
                        max2[x] = u;
                    }
                }
                u = max2[y];
                if (u != max1[x] && u != max2[x])
                {
                    if (u >= max1[x])
                    {
                        max2[x] = max1[x];
                        max1[x] = u;
                    }
                    else if (u >= max2[x])
                    {
                        max2[x] = u;
                    }
                }
            }
        }
        if (max1[x] && max2[x])
        {
            assert(max1[x] != max2[x]);
            ans = max(ans, max1[x] * 1LL * max2[x] - k * 1LL * x);
        }
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