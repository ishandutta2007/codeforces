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
const int N = 100005;
const ll M = 4000000009000000009;

int n;
ll k;
ll a[N];

ll stg(ll x)
{
    ll k = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll l = 0, r = a[i];
        ll u = 0;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            ll s = a[i] - 3 * m * m + 3 * m - 1;
            if (s >= x)
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        k += u;
    }
    return k;
}

ll b[N];

void solv()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    ll l = -M, r = M;
    assert(stg(-M) >= k);
    ll x;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m) >= k)
        {
            x = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    vector<pair<ll, int> > v;
    ll kk = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll l = 0, r = a[i];
        ll u = 0;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            ll s = a[i] - 3 * m * m + 3 * m - 1;
            if (s >= x)
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        kk += u;
        b[i] = u;
        if (u)
        {
            v.push_back(m_p(a[i] - 3 * u * u + 3 * u - 1, i));
        }
    }
    sort(all(v));
    for (int i = 0; i < (kk - k); ++i)
        b[v[i].se]--;

    for (int i = 1; i <= n; ++i)
        printf("%lld ", b[i]);
    printf("\n");
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