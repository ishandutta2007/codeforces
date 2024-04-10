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

void solv()
{
    int a, b, x, y, n;
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
    int cn = n;
    int ca = a;
    int cb = b;

    ll ans;
    {
        if ((a - x) <= n)
        {
            n -= (a - x);
            a = x;
        }
        else
        {
            a -= n;
            n = 0;
        }
        b = max(y, b - n);
        ans = a * 1LL * b;
    }
    {
        n = cn;
        a = ca;
        b = cb;
        swap(a, b);
        swap(x, y);
        if ((a - x) <= n)
        {
            n -= (a - x);
            a = x;
        }
        else
        {
            a -= n;
            n = 0;
        }
        b = max(y, b - n);
        ans = min(ans, a * 1LL * b);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}