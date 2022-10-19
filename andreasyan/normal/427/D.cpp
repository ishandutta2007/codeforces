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
const int N = 5003;

int n, m;
char a[N], b[N];

int aa[N], bb[N];

char u[N + N];
int z[N + N];
void solvv(int n, char a[], int maxu[])
{
    for (int i = 0; i < n; ++i)
    {
        int m = 0;
        for (int j = i; j < n; ++j)
            u[m++] = a[j];
        u[m++] = '#';
        for (int j = 0; j < n; ++j)
            u[m++] = a[j];
        u[m] = 0;
        int k = 0, r = 0;
        for (int j = 1; j < m; ++j)
        {
            z[j] = 0;
            if (j <= r)
                z[j] = min(r - j + 1, z[j - k]);
            while (u[z[j]] == u[j + z[j]])
                ++z[j];
            if (j + z[j] - 1 > r)
            {
                r = j + z[j] - 1;
                k = j;
            }
        }
        maxu[i] = 0;
        for (int j = (n - i); j < m; ++j)
        {
            if (j - (n - i) - 1 == i)
                continue;
            maxu[i] = max(maxu[i], z[j] + 1);
        }
    }
}

int dp[N][N];

void solv()
{
    scanf(" %s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    solvv(n, a, aa);
    solvv(m, b, bb);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }
    int ans = N * N;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j] >= max(aa[i], bb[j]))
                ans = min(ans, max(aa[i], bb[j]));
        }
    }
    if (ans == N * N)
        printf("-1\n");
    else
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