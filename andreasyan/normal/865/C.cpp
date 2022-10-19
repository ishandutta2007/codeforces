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
const int N = 55, H = 102, R = N * H;

int n, r;
int f[N], s[N];
double p[N];

double dp[N][R];
double stg(double k)
{
    for (int j = 0; j < (n + 1) * H; ++j)
    {
        dp[n + 1][j] = j;
        if (j > r)
            dp[n + 1][j] = j + k;
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < i * H; ++j)
        {
            dp[i][j] = min(j + k, p[i] * dp[i + 1][j + f[i]] + (1 - p[i]) * dp[i + 1][j + s[i]]);
            if (j > r)
                dp[i][j] = j + k;
        }
    }
    return dp[1][0];
}

void solv()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
    {
        int pp;
        scanf("%d%d%d", &f[i], &s[i], &pp);
        p[i] = pp / (double)(100);
    }

    double l = 0, r = R * 1LL * R * R;
    for (int ii = 0; ii < H; ++ii)
    {
        double m = (l + r) / 2;
        if (stg(m) >= m)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    printf("%.12f\n", l);
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