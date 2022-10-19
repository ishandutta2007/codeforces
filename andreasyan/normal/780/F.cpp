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
bitset<N> a[2][60][N];

void solv()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[z][0][x][y] = 1;
    }
    for (int k = 0; k < 59; ++k)
    {
        for (int z = 0; z < 2; ++z)
        {
            for (int x = 1; x <= n; ++x)
            {
                for (int y = 1; y <= n; ++y)
                {
                    if (a[z][k][x][y])
                    {
                        a[z][k + 1][x] |= a[(z ^ 1)][k][y];
                    }
                }
            }
        }
    }
    ll ans = 0;
    bitset<N> u;
    u[1] = 1;
    int z = 0;
    for (int k = 59; k >= 0; --k)
    {
        bool f = false;
        for (int x = 1; x <= n; ++x)
        {
            if (u[x])
            {
                for (int y = 1; y <= n; ++y)
                {
                    if (a[z][k][x][y])
                    {
                        f = true;
                        break;
                    }
                }
                if (f)
                    break;
            }
        }
        if (f)
        {
            ans += (1LL << k);
            bitset<N> nu;
            for (int x = 1; x <= n; ++x)
            {
                if (u[x])
                    nu |= a[z][k][x];
            }
            u = nu;
            z ^= 1;
        }
    }
    if (ans > 1000000000000000000)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}