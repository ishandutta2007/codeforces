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
const int N = 1003, n = 999;

int x, y;
int nx[N], ny[N];

bool c[N][N];
int qx[N], qy[N];

void solv()
{
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= 666; ++i)
    {
        scanf("%d%d", &nx[i], &ny[i]);
        c[nx[i]][ny[i]] = true;
        qx[nx[i]]++;
        qy[ny[i]]++;
    }

    int u = 0;
    while (1)
    {
        if (u == 0)
        {
            bool z = false;
            for (int i = -1; i <= 1; ++i)
            {
                int hx = x + i;
                int hy = y + 1;
                if (hx >= 1 && hx <= n && hy >= 1 && hy <= n && !c[hx][hy])
                {
                    z = true;
                    x = hx;
                    y = hy;
                    break;
                }
            }
            if (z)
            {
                printf("%d %d\n", x, y);
                fflush(stdout);
                if (qx[x] || qy[y])
                {
                    return;
                }
            }
            else
            {
                u = 1;
                continue;
            }
        }
        else
        {
            bool z = false;
            for (int i = -1; i <= 1; ++i)
            {
                int hx = x + i;
                int hy = y - 1;
                if (hx >= 1 && hx <= n && hy >= 1 && hy <= n && !c[hx][hy])
                {
                    z = true;
                    x = hx;
                    y = hy;
                    break;
                }
            }
            if (z)
            {
                printf("%d %d\n", x, y);
                fflush(stdout);
                if (qx[x] || qy[y])
                {
                    return;
                }
            }
            else
            {
                u = 0;
                continue;
            }
        }
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == -1)
            return;
        c[nx[k]][ny[k]] = false;
        --qx[nx[k]];
        --qy[ny[k]];
        nx[k] = x;
        ny[k] = y;
        c[nx[k]][ny[k]] = true;
        ++qx[nx[k]];
        ++qy[ny[k]];
    }
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