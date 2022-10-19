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
const int N = 1000006;

int n, m;

int dp[(1 << 3)];
int ndp[(1 << 3)];

int q[(1 << 3)];
bool c[(1 << 3)][(1 << 3)];
void clc()
{
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q[x];
        }
    }
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int y = 0; y < (1 << n); ++y)
        {
            c[x][y] = true;
            for (int i = 0; i < n - 1; ++i)
            {
                int q = 0;
                if ((x & (1 << i)))
                    ++q;
                if ((x & (1 << (i + 1))))
                    ++q;
                if ((y & (1 << i)))
                    ++q;
                if ((y & (1 << (i + 1))))
                    ++q;
                if (q % 2 == 0)
                {
                    c[x][y] = false;
                    break;
                }
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    char** a;
    a = new char*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new char[m + 5];
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", a[i]);
    }
    if (n >= 4)
    {
        printf("-1\n");
        return;
    }
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    clc();
    for (int x = 1; x < (1 << n); ++x)
    {
        dp[x] = N;
    }
    for (int j = 0; j < m; ++j)
    {
        for (int x = 0; x < (1 << n); ++x)
            ndp[x] = N;
        int z = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((a[i][j]) == '1')
                z |= (1 << i);
        }
        for (int x = 0; x < (1 << n); ++x)
        {
            for (int y = 0; y < (1 << n); ++y)
            {
                if (j == 0 || c[x][y])
                {
                    ndp[y] = min(ndp[y], dp[x] + q[(y ^ z)]);
                }
            }
        }
        for (int x = 0; x < (1 << n); ++x)
            dp[x] = ndp[x];
    }
    int ans = N;
    for (int x = 0; x < (1 << n); ++x)
        ans = min(ans, dp[x]);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}