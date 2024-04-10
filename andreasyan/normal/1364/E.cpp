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
const int N = 2303, m = 11;

int n;

int aa[N] = {0, 1, 0, 2, 3, 4, 5};

int qry(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int z;
    scanf("%d", &z);
    //z = aa[x] | aa[y];
    return z;
}

int u[m];

int qry1(int x)
{
    int z = (1 << m) - 1;
    for (int i = 0; i < m; ++i)
    {
        if (x == u[i])
        {
            if ((z & (1 << i)))
                z ^= (1 << i);
            continue;
        }
        z &= qry(x, u[i]);
    }
    return z;
}

int a[N];

void solv()
{
    scanf("%d", &n);
    while (1)
    {
        int x = rnd() % n + 1;
        int y;
        while (1)
        {
            y = rnd() % n + 1;
            if (y == x)
                continue;
            break;
        }
        int z = qry(x, y);
        for (int i = 0; i < m; ++i)
        {
            if (!(z & (1 << i)))
                u[i] = x;
        }
        bool f = true;
        for (int i = 0; i < m; ++i)
        {
            if (!u[i])
            {
                f = false;
                break;
            }
        }
        if (f)
            break;
    }
    int i0 = 1, z0 = qry1(1);
    for (int i = 2; i <= n; ++i)
    {
        if (qry(i0, i) != z0)
            continue;
        i0 = i;
        z0 = qry1(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == i0)
            a[i] = 0;
        else
            a[i] = qry(i, i0);
    }
    printf("!\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}