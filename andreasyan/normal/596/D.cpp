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

int n, h;
char pp[10];
double p;
int x[N];

int ul[N], ur[N];

double dp[N][N][2][2];
double dpp[N][N][2][2];

int hat(pair<int, int> a, pair<int, int> b)
{
    if (max(a.fi, b.fi) > min(a.se, b.se))
        return 0;
    return min(a.se, b.se) - max(a.fi, b.fi);
}

void solv()
{
    scanf("%d %d %s", &n, &h, &pp);
    double uu = 0.1;
    for (int i = 2; i < strlen(pp); ++i)
    {
        p += uu * (pp[i] - '0');
        uu *= 0.1;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && x[i - 1] > x[i] - h)
            ul[i] = ul[i - 1];
        else
            ul[i] = i;
    }
    for (int i = n; i >= 1; --i)
    {
        if (i < n && x[i + 1] < x[i] + h)
            ur[i] = ur[i + 1];
        else
            ur[i] = i;
    }
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            for (int u = 0; u < 2; ++u)
            {
                for (int k = 0; k < 2; ++k)
                {
                    double pp = 0.5;
                    if (k == 0)
                        pp *= p;
                    else
                        pp *= (1 - p);
                    int l1, r1;
                    int xl, xr;
                    if (u == 0 && k == 0)
                    {
                        l1 = l + 1;
                        r1 = r;
                        xl = x[l] - h;
                        xr = x[l];
                    }
                    else if (u == 0 && k == 1)
                    {
                        l1 = ur[l] + 1;
                        r1 = r;
                        xl = x[l];
                        xr = x[min(r, ur[l])] + h;
                    }
                    else if (u == 1 && k == 1)
                    {
                        l1 = l;
                        r1 = r - 1;
                        xl = x[r];
                        xr = x[r] + h;
                    }
                    else
                    {
                        l1 = l;
                        r1 = ul[r] - 1;
                        xl = x[max(l, ul[r])] - h;
                        xr = x[r];
                    }
                    if (l1 > r1)
                    {
                        dpp[l][r][k][k] += pp;
                        dp[l][r][k][k] += pp * (xr - xl);
                        continue;
                    }
                    for (int zl = 0; zl < 2; ++zl)
                    {
                        for (int zr = 0; zr < 2; ++zr)
                        {
                            int d = 0;
                            if (zl == 0)
                                d += hat(m_p(xl, xr), m_p(x[l1] - h, x[l1]));
                            if (zr == 1)
                                d += hat(m_p(xl, xr), m_p(x[r1], x[r1] + h));
                            if (u == 0)
                            {
                                dpp[l][r][k][zr] += pp * dpp[l1][r1][zl][zr];
                                dp[l][r][k][zr] += dp[l1][r1][zl][zr] * pp + ((xr - xl) - d) * dpp[l1][r1][zl][zr] * pp;
                            }
                            else
                            {
                                dpp[l][r][zl][k] += pp * dpp[l1][r1][zl][zr];
                                dp[l][r][zl][k] += dp[l1][r1][zl][zr] * pp + ((xr - xl) - d) * dpp[l1][r1][zl][zr] * pp;
                            }
                        }
                    }
                }
            }
        }
    }
    double ans = dp[1][n][0][0] + dp[1][n][0][1] + dp[1][n][1][0] + dp[1][n][1][1];
    printf("%.9f\n", ans);
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