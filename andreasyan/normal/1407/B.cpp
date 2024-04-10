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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];
bool c[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        c[i] = false;
    }
    int x = 0;
    for (int ii = 0; ii < n; ++ii)
    {
        int maxu = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            maxu = max(maxu, gcd(a[i], x));
        }
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            if (maxu == gcd(a[i], x))
            {
                printf("%d ", a[i]);
                c[i] = true;
                break;
            }
        }
        x = maxu;
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}