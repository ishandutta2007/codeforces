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
const int N = 404;

int n, m;
char a[N][N];

int p[N][N];

int u0[N], u1[N];

int p1[N];
int minu[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            a[i][j] -= '0';
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[i][j] = p[i - 1][j] + a[i][j];
        }
    }

    int ans = n * m;
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int x2 = x1 + 4; x2 <= n; ++x2)
        {
            for (int j = 1; j <= m; ++j)
            {
                u0[j] = (x2 - x1 - 1) - (p[x2 - 1][j] - p[x1][j]);
                u1[j] = (p[x2 - 1][j] - p[x1][j]);
                if (a[x1][j] == 0)
                    ++u1[j];
                if (a[x2][j] == 0)
                    ++u1[j];
            }

            for (int j = 1; j <= m; ++j)
                p1[j] = p1[j - 1] + u1[j];

            minu[0] = n * m;
            for (int j = 1; j <= m; ++j)
                minu[j] = min(minu[j - 1], u0[j] - p1[j]);

            for (int r = 4; r <= m; ++r)
            {
                int yans = u0[r] + p1[r - 1] + minu[r - 3];
                ans = min(ans, yans);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}