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

int a, b, c, d;

int hat(int l1, int r1, int l2, int r2)
{
    if (min(r1, r2) < max(l1, l2))
        return 0;
    return min(r1, r2) - max(l1, l2) + 1;
}

void solv()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 0;
    for (int z = c; z <= d; ++z)
    {
        int d = hat(z - c, z - b, a - 1, b - 1);
        ans += (d * 1LL * (d + 1)) / 2;
        if (z - b < b - 1)
            ans += (d * 1LL * (b - 1 - (z - b)));
        if (z - b < a - 1)
        {
            ans += ((c - b + 1) * 1LL * (b - a + 1));
        }
        else if (z - c < a - 1)
        {
            ans += ((a - 2 - (z - c) + 1) * 1LL * (b - a + 1));
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