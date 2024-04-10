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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void por()
{
    int n = 223;
    for (int i = 1; i <= n; ++i)
    {
        //printf("%d\n", i);
        bool f = false;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            int x = gcd(i, j);
            int y = i / x;
            int z = j / x;
            if (x + y > z && x + z > y && y + z > x)
            {
                //printf("%d ", j);
                f = true;
                break;
            }
        }
        //printf("\n");
        bool ff = true;
        if (i * 1LL * i > n && prime(i) || i == 1)
            ff = false;
        assert(f == ff);
        /*if (!f)
        {
            printf("%d\n", i);
        }*/
    }
}

bool c[N];
int p[N];
void solv()
{
    c[0] = true;
    c[1] = true;
    for (int i = 2; i < N; ++i)
    {
        if (c[i])
            continue;
        if (i * 1LL * i >= N)
            break;
        for (int j = i * i; j < N; j += i)
            c[j] = true;
    }
    for (int i = 1; i < N; ++i)
    {
        p[i] = p[i - 1];
        if (!c[i])
            ++p[i];
    }
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", p[n] - p[(int)sqrt(n)] + 1);
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