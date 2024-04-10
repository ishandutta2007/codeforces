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
const ll INF = 1000000009000000009;

int n;
int a[N];

ll p[N][2];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        p[i][0] = p[i - 1][0];
        p[i][1] = p[i - 1][1];
        p[i][(i % 2)] += a[i];
    }
    ll ans = p[n][1];
    ll maxu[2] = {-INF, -INF};
    maxu[0] = p[0][1] - p[0][0];
    for (int r = 1; r <= n; ++r)
    {
        ans = max(ans, p[n][1] - p[r][1] + p[r][0] + maxu[r % 2]);
        maxu[r % 2] = max(maxu[r % 2], p[r][1] - p[r][0]);
    }
    printf("%lld\n", ans);
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