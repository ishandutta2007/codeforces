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

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
ll k;
ll a[N];

void solv()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    k -= a[1];
    for (int i = 2; i <= n; ++i)
        a[i] -= a[1];

    ll g = 0;
    for (int i = 2; i <= n; ++i)
        g = gcd(g, abs(a[i]));

    if (abs(k) % g == 0)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}