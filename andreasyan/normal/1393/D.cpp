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
const int N = 2003;

int n, m;
char a[N][N];

int q[N][N][4];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1])
                q[i][j][0] = min(q[i - 1][j][0], q[i][j - 1][0]) + 1;
            else
                q[i][j][0] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j + 1])
                q[i][j][1] = min(q[i - 1][j][1], q[i][j + 1][1]) + 1;
            else
                q[i][j][1] = 1;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j - 1])
                q[i][j][2] = min(q[i + 1][j][2], q[i][j - 1][2]) + 1;
            else
                q[i][j][2] = 1;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1])
                q[i][j][3] = min(q[i + 1][j][3], q[i][j + 1][3]) + 1;
            else
                q[i][j][3] = 1;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int minu = q[i][j][0];
            for (int k = 1; k < 4; ++k)
                minu = min(minu, q[i][j][k]);
            ans += minu;
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
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}