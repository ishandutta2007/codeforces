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

int n;
char a[N][N];

bool b[N][N];

int d0[N];
int d[N];
bool z[N];

int ans[10];
void solvv()
{
    for (char u = '0'; u <= '9'; ++u)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == u)
                    b[i][j] = true;
                else
                    b[i][j] = false;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            d0[i] = d[i] = 0;

            int l = n + 1;
            for (int j = 1; j <= n; ++j)
            {
                if (b[i][j])
                {
                    l = j;
                    break;
                }
            }

            int r = 0;
            for (int j = n; j >= 1; --j)
            {
                if (b[i][j])
                {
                    r = j;
                    break;
                }
            }

            z[i] = false;
            if (l > r)
                continue;

            z[i] = true;
            d0[i] = (r - l);
            d[i] = max(n - l, r - 1);
        }
        for (int i1 = 1; i1 <= n; ++i1)
        {
            for (int i2 = 1; i2 <= n; ++i2)
            {
                if (z[i1])
                {
                    ans[u - '0'] = max(ans[u - '0'], abs(i1 - i2) * d[i2]);
                }
                else
                {
                    ans[u - '0'] = max(ans[u - '0'], abs(i1 - i2) * d0[i2]);
                }
            }
        }
    }
}

char aa[N][N];
bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));

    memset(ans, 0, sizeof ans);
    solvv();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            aa[i][j] = a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[j][i] = aa[i][j];
        }
    }
    solvv();

    for (int i = 0; i < 10; ++i)
        printf("%d ", ans[i]);
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
    {
        solv();
    }
    return 0;
}