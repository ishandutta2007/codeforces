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
const int M = 1000006, N = 502;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
int lca(int x, int y)
{
    return x / gcd(x, y) * y;
}

bool c[M];
int u = 1;
int h[20];

void pre()
{
    for (int i = 1; i * i * i * i < M; ++i)
        c[i * i * i * i] = true;

    for (int i = 1; i <= 16; ++i)
        u = lca(u, i);

    for (int i = 1; i <= 16; ++i)
    {
        bool z = false;
        for (int j = i; j <= 1000000; j += i)
        {
            int x = abs(j - u);
            if (c[x])
            {
                h[i] = j;
                z = true;
                break;
            }
        }
        assert(z);
    }
}

int n, m;
int a[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) % 2 == 0)
                printf("%d ", u);
            else
                printf("%d ", h[a[i][j]]);
        }
        printf("\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}