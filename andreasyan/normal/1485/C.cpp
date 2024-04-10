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

int x, y;

void solv()
{
    scanf("%d%d", &x, &y);

    ll ans = 0;
    for (int i = 1; i <= y; ++i)
    {
        if (i * i <= x + 100)
        {
            ans += min(i - 1, (x / (i + 1)));
            continue;
        }

        int l = i, r = y;
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if ((x / (m + 1)) == ((x / (i + 1))))
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        ans += (u - i + 1) * 1LL * ((x / (i + 1)));
        i = u;
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
    /*int b = 10;
    for (int a = 0; a <= 57; ++a)
        printf("%d ", a / b);
    printf("\n");
    for (int a = 0; a <= 57; ++a)
        printf("%d ", a % b);
    printf("\n");*/

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}