#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, M = 1000000007;
struct ban
{
    int l, r;
    ban(){}
    ban(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

pair<int, int> dp[N];
pair<int, int> p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].r, &a[i].l);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i - 1;
        int u = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m].r <= a[i].l)
            {
                u = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (!u)
        {
            dp[i] = m_p(a[i].l, 1);
        }
        else
        {
            dp[i] = m_p(p[u].fi + a[i].l, p[u].se);
        }
        p[i] = p[i - 1];
        if (i > 1 && dp[i].fi - a[i].r == p[i - 1].fi)
        {
            p[i].se = (p[i - 1].se + dp[i].se) % M;
        }
        else if (i == 1 || dp[i].fi - a[i].r < p[i - 1].fi)
        {
            p[i] = m_p(dp[i].fi - a[i].r, dp[i].se);
        }
    }
    int maxl = 0;
    for (int i = 1; i <= n; ++i)
        maxl = max(maxl, a[i].l);
    int minu = M;
    for (int i = 1; i <= n; ++i)
    {
        if (!(a[i].r <= maxl))
            minu = min(minu, dp[i].fi);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!(a[i].r <= maxl))
        {
            if (minu == dp[i].fi)
            {
                ans = (ans + dp[i].se) % M;
            }
        }
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