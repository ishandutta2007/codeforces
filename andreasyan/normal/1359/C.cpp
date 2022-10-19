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
const ll INF = 2003000000009;

ll h, c, t;

ll so(ll x1, ll y1_, ll x2, ll y2)
{
    return (x1 * y2 - y1_ * x2);
}

void solv()
{
    scanf("%lld%lld%lld", &h, &c, &t);
    ll l = 0, r = INF;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll x = m * (c + h) + h;
        ll y = m * 2 + 1;
        if (x <= t * y)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    ll yans = 2;
    ll ansx = c + h - 2 * t;
    if (ansx < 0)
        ansx *= -1;
    ll ansy = 2;
    ll x = ans * (c + h) + h - (ans * 2 + 1) * t;
    if (x < 0)
        x *= -1;
    ll y = ans * 2 + 1;
    if (so(x, y, ansx, ansy) < 0 || (so(x, y, ansx, ansy) == 0 && ans * 2 + 1 < yans))
    {
        yans = ans * 2 + 1;
        ansx = x;
        ansy = y;
    }
    --ans;
    if (ans < 0)
    {
        printf("%lld\n", yans);
        return;
    }
    x = ans * (c + h) + h - (ans * 2 + 1) * t;
    if (x < 0)
        x *= -1;
    y = ans * 2 + 1;
    if (so(x, y, ansx, ansy) < 0 || (so(x, y, ansx, ansy) == 0 && ans * 2 + 1 < yans))
    {
        yans = ans * 2 + 1;
        ansx = x;
        ansy = y;
    }
    printf("%lld\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*double c, h;
    cin >> c >> h;
    double s = 0;
    for (int i = 1; i <= 50; ++i)
    {
        if (i % 2 == 1)
            s += h;
        else
            s += c;
        if (i % 2 == 1)
        {
            cout << (s / i) << endl;
        }
    }
    return 0;*/
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}