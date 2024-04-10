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
const int N = 500015;
const ll M = 1000000007;

int n;
ll x[N];

ll qq[N][2];
void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &x[i]);

    ll ans = 0;

    int q[60] = {};
    for (int i = 0; i < 60; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            if ((x[u] & (1LL << i)))
                ++q[i];
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        qq[u][0] = qq[u][1] = 0;
        for (int i = 0; i < 60; ++i)
        {
            if ((x[u] & (1LL << i)))
                qq[u][0] = (qq[u][0] + ((1LL << i) % M) * n % M) % M;
            else
                qq[u][0] = (qq[u][0] + ((1LL << i) % M) * q[i] % M) % M;
        }
    }

    for (int i = 0; i < 60; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            if ((x[u] & (1LL << i)))
            {
                ll pans = q[i];
                pans = (pans * ((1LL << i) % M)) % M;
                pans *= qq[u][0];
                ans = (ans + pans) % M;
                pans = q[i];
                pans = (pans * ((1LL << i) % M)) % M;
                pans *= qq[u][1];
                ans = (ans + pans) % M;
            }
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}