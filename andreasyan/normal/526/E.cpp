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

int n, qq;
int a[N];
ll p[N];

int u[N];

int q[N], uu[N];
ll d[N];

bool solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    while (qq--)
    {
        ll b;
        scanf("%lld", &b);
        int j = n;
        ll s = 0;
        for (int i = n; i >= 1; --i)
        {
            s += a[i];
            while (s > b)
            {
                s -= a[j];
                --j;
            }
            u[i] = j;
        }
        uu[n + 1] = n + 1;
        for (int i = n; i >= 1; --i)
        {
            uu[i] = uu[u[i] + 1];
            q[i] = q[u[i] + 1] + 1;
            if (u[i] == n)
                d[i] = p[n] - p[i - 1];
            else
                d[i] = d[u[i] + 1];
        }
        int ans = N;
        for (int i = 1; i <= n; ++i)
        {
            if (d[i] + p[i - 1] <= b)
                ans = min(ans, q[i]);
        }
        printf("%d\n", ans);
    }
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