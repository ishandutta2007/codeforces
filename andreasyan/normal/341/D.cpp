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
const int N = 1003;

int n;
ll t[N][N][4];

void ubdy(int x, int y, ll z, int u)
{
    while (y <= n)
    {
        t[x][y][u] ^= z;
        y += (y & (-y));
    }
}

void ubdx(int x, int y, ll z, int u)
{
    while (x <= n)
    {
        ubdy(x, y, z, u);
        x += (x & (-x));
    }
}

void ubdd(int x1, int y1_, int x2, int y2, ll z, int u)
{
    ubdx(x1, y1_, z, u);
    ubdx(x2 + 1, y1_, z, u);
    ubdx(x1, y2 + 1, z, u);
    ubdx(x2 + 1, y2 + 1, z, u);
}

void ubd(int x1, int y1_, int x2, int y2, ll z)
{
    int u = (x1 % 2) * 2 + (y1_ % 2);
    ubdd(x1, y1_, x2, y2, z, u);
    if ((y2 - y1_ + 1) % 2 == 1)
    {
        int u0 = (x1 % 2) * 2 + 0;
        int u1 = (x1 % 2) * 2 + 1;
        ubdd(x1, y2 + 1, x2, n, z, u0);
        ubdd(x1, y2 + 1, x2, n, z, u1);
    }
    if ((x2 - x1 + 1) % 2 == 1)
    {
        int u0 = 0 * 2 + (y1_ % 2);
        int u1 = 1 * 2 + (y1_ % 2);
        ubdd(x2 + 1, y1_, n, y2, z, u0);
        ubdd(x2 + 1, y1_, n, y2, z, u1);
    }
    if (((y2 - y1_ + 1) * (x2 - x1 + 1)) % 2 == 1)
    {
        ubdd(x2 + 1, y2 + 1, n, n, z, 0);
        ubdd(x2 + 1, y2 + 1, n, n, z, 1);
        ubdd(x2 + 1, y2 + 1, n, n, z, 2);
        ubdd(x2 + 1, y2 + 1, n, n, z, 3);
    }
}

ll qryy(int x, int y, int u)
{
    ll ans = 0;
    while (y)
    {
        ans ^= t[x][y][u];
        y -= (y & (-y));
    }
    return ans;
}

ll qryx(int x, int y)
{
    int u = (x % 2) * 2 + (y % 2);
    ll ans = 0;
    while (x)
    {
        ans ^= qryy(x, y, u);
        x -= (x & (-x));
    }
    return ans;
}

ll qry(int x1, int y1_, int x2, int y2)
{
    return qryx(x2, y2) ^ qryx(x2, y1_ - 1) ^ qryx(x1 - 1, y2) ^ qryx(x1 - 1, y1_ - 1);
}

void solv()
{
    int qq;
    scanf("%d%d", &n, &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x1, y1_, x2, y2;
            scanf("%d%d%d%d", &x1, &y1_, &x2, &y2);
            printf("%lld\n", qry(x1, y1_, x2, y2));
        }
        else
        {
            int x1, y1_, x2, y2;
            ll z;
            scanf("%d%d%d%d%lld", &x1, &y1_, &x2, &y2, &z);
            ubd(x1, y1_, x2, y2, z);
        }
    }
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