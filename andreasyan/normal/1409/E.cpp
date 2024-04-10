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

int n, k;
int a[N];

int u[N];
int maxu[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[0]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = i, r = n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[i] + k >= a[m])
            {
                u[i] = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }

    maxu[n + 1] = 0;
    for (int i = n; i >= 1; --i)
    {
        maxu[i] = max(maxu[i + 1], u[i] - i + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, u[i] - i + 1 + maxu[u[i] + 1]);
    }

    printf("%d\n", ans);
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