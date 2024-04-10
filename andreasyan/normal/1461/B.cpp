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
const int N = 502;

int n, m;
char a[N][N];

int p[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[i][j] = (p[i][j - 1] + !!(a[i][j] == '*'));
        }
    }

    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            for (int i = 1; ; ++i)
            {
                if (x + i - 1 > n)
                    break;
                if (y - i + 1 < 1)
                    break;
                if (y + i - 1 > m)
                    break;
                if (p[x + i - 1][y + i - 1] - p[x + i - 1][y - i] != (i - 1) * 2 + 1)
                    break;
                ++ans;
            }
        }
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