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
const ll INF = 1000000009000000009;

ll n, k;
ll l1, r1, l2, r2;

void solv()
{
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld", &l1, &r1);
    scanf("%lld%lld", &l2, &r2);
    if (r1 > r2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }

    ll d = 0;
    ll d0 = 0;
    if (max(l1, l2) < min(r1, r2))
        d0 = min(r1, r2) - max(l1, l2);
    d = d0 * 1LL * n;
    if (d >= k)
    {
        printf("0\n");
        return;
    }

    ll ans = INF;
    if (!d0)
    {
        for (ll q = 1; q <= n; ++q)
        {
            ll yans = 0;
            yans += q * 1LL * (max(l1, l2) - min(r1, r2));
            ll u = (max(r1, r2) - min(l1, l2)) * 1LL * q;
            if (k <= u)
                yans += k;
            else
            {
                yans += u;
                yans += (k - u) * 2;
            }
            ans = min(ans, yans);
        }
        printf("%lld\n", ans);
    }
    else
    {
        ans = 0;
        k -= d;
        ll u = (max(r1, r2) - min(l1, l2) - d0) * 1LL * n;
        if (k <= u)
            ans += k;
        else
        {
            ans += u;
            ans += (k - u) * 2;
        }
        printf("%lld\n", ans);
    }
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}