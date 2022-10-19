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
const int N = 200005, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N];
int rf[N];

void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int c(int n, int k)
{
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n, m, k;
ban a[N];

int dp[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + k + 1);
    for (int i = 1; i <= k; ++i)
    {
        dp[i] = c(a[i].x - 1 + a[i].y - 1, a[i].x - 1);
        for (int j = 1; j < i; ++j)
        {
            if (a[j].x <= a[i].x && a[j].y <= a[i].y)
            {
                dp[i] = (dp[i] - (c(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x) * 1LL * dp[j]) % M + M) % M;
            }
        }
    }
    int ans = c(n - 1 + m - 1, n - 1);
    for (int i = 1; i <= k; ++i)
        ans = (ans - (dp[i] * 1LL * c(n - a[i].x + m - a[i].y, n - a[i].x)) % M + M) % M;
    printf("%d\n", ans);
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