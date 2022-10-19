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
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int ans = 1000000009;
    int dd;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if ((y - x) % (j - i) != 0)
                continue;
            int d = (y - x) / (j - i);
            int minu = x - (i - 1) * d;
            if (minu <= 0)
                continue;
            if (y + (n - j) * d < ans)
            {
                ans = y + (n - j) * d;
                dd = d;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans - (n - i) * dd);
    printf("\n");
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