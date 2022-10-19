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
const int N = 1003;

int n, m, x, y;
char a[N][N];

void solv()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    y = min(y, 2 * x);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '.')
                ++q;
            else
            {
                ans += (q / 2) * y;
                ans += (q % 2) * x;
                q = 0;
            }
        }
        ans += (q / 2) * y;
        ans += (q % 2) * x;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}