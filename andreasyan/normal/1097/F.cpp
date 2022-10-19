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
const int N = 7003, M = 100005;

bitset<N> b[N], d[N], c[N];

bool stg(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            x /= i;
            if (x % i == 0)
                return false;
        }
    }
    return true;
}

void pre()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
        {
            b[j][i] = 1;
            c[i][j] = 1;
        }
    }
    for (int i = N - 1; i >= 1; --i)
    {
        d[i] = c[i];
        for (int j = i + i; j < N; j += i)
        {
            if (!d[i][j])
                continue;
            d[i] ^= c[j];
            d[i][j] = 1;
        }
    }
}

int n, qq;

bitset<N> a[M];

void solv()
{
    scanf("%d%d", &n, &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, v;
            scanf("%d%d", &x, &v);
            a[x] = b[v];
        }
        else if (ty == 2)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[x] = (a[y] ^ a[z]);
        }
        else if (ty == 3)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            a[x] = (a[y] & a[z]);
        }
        else
        {
            int x, v;
            scanf("%d%d", &x, &v);
            if (((a[x] & d[v]).count()) % 2 == 0)
                putchar('0');
            else
                putchar('1');
        }
    }
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}