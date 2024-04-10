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
const int N = 100005;
const ll INF = 1000000009003;

int n, k;
int a[N];

ll yc;
int ql = 1, qr;
int q[N];

void ubd(int x, int y)
{
    yc -= (q[x] * 1LL * (q[x] - 1)) / 2;
    q[x] += y;
    yc += (q[x] * 1LL * (q[x] - 1)) / 2;
}

void go(int l, int r)
{
    while (ql > l)
    {
        --ql;
        ubd(a[ql], 1);
    }
    while (qr < r)
    {
        ++qr;
        ubd(a[qr], 1);
    }
    while (ql < l)
    {
        ubd(a[ql], -1);
        ++ql;
    }
    while (qr > r)
    {
        ubd(a[qr], -1);
        --qr;
    }
}

ll dp[N], ndp[N];

void bil(int l, int r, int l0, int r0)
{
    if (l > r)
    {
        return;
    }
    int m = (l + r) / 2;
    ndp[m] = INF;
    int m0 = l0;
    for (int i = r0; i >= l0; --i)
    {
        go(i, m);
        if (yc + dp[i - 1] <= ndp[m])
        {
            ndp[m] = yc + dp[i - 1];
            m0 = i;
        }
    }
    bil(l, m - 1, l0, m0);
    bil(m + 1, r, m0, r0);
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        go(1, i);
        dp[i] = yc;
    }
    dp[0] = INF;
    for (int ii = 2; ii <= k; ++ii)
    {
        bil(1, n, 1, n);
        ndp[0] = INF;
        memcpy(dp, ndp, sizeof ndp);
    }
    printf("%lld\n", dp[n]);
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