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
const int N = 200005;

int n;
int a[N];
int p[N];

const int m = 30;
int u[m];

void ave(int x)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if ((x & (1 << i)))
        {
            if (!u[i])
            {
                u[i] = x;
                return;
            }
            else
                x ^= u[i];
        }
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] ^ a[i]);
    if (p[n] == 0)
    {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
        ave(p[i]);
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (u[i])
            ++ans;
    }
    printf("%d\n", ans);
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