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
const int N = 10001027;
const ll INF = 100000070000007;

int k;

int c[N];
ll s[N];
ll q[N];

bool stg(ll n, int p, ll q)
{
    ll y = p;
    while (y <= n)
    {
        q -= (n / y);
        if (y > (long double)n / p)
            break;
        y *= p;
    }
    return (q <= 0);
}

void solv()
{
    int k;
    scanf("%d", &k);
    while (k--)
    {
        int x;
        scanf("%d", &x);
        ++s[x];
    }
    for (int i = N - 2; i >= 0; --i)
        s[i] += s[i + 1];
    c[0] = c[1] = 0;
    for (int i = 2; i < N; ++i)
    {
        if (c[i])
            continue;
        c[i] = i;
        if (i * 1LL * i >= N)
            continue;
        for (int j = i * i; j < N; j += i)
        {
            if (!c[j])
                c[j] = i;
        }
    }
    for (int i = 2; i < N; ++i)
    {
        int x = i;
        while (x > 1)
        {
            q[c[x]] += s[i];
            x /= c[x];
        }
    }
    ll ans = 1;
    for (int i = 2; i < N; ++i)
    {
        if (i != c[i])
            continue;
        if (stg(ans, i, q[i]))
            continue;
        ll l = ans + 1, r = INF;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            if (stg(m, i, q[i]))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}