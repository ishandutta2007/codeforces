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
const int N = 100005, m = 55;

int n;
ll a[N];

ll p[N];

int z;
int t[N * m][2];

void ave(ll x)
{
    int pos = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        int u = 0;
        if ((x & (1LL << i)))
            u = 1;

        if (!t[pos][u])
            t[pos][u] = ++z;
        pos = t[pos][u];
    }
}

ll qry(ll x)
{
    ll ans = 0;
    int pos = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        int u = 0;
        if ((x & (1LL << i)))
            u = 1;

        if (t[pos][(u ^ 1)])
        {
            ans += (1LL << i);
            pos = t[pos][(u ^ 1)];
        }
        else
            pos = t[pos][u];
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] ^ a[i];

    ll ans = 0;
    ave(0);
    for (int i = 1; i <= n + 1; ++i)
    {
        ans = max(ans, qry((p[n] ^ p[i - 1])));
        ave(p[i]);
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}