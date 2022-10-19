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

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    if (k == -1)
        return 0;
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

int n;
ll T;
int t[N];

ll p[N];

int yc = 0;
int i = 0;
int j = -1;

void go(int jj)
{
    while (j < jj)
    {
        ++j;
        yc = (yc + C(i, j)) % M;
    }
    while (j > jj)
    {
        yc = (yc - C(i, j) + M) % M;
        --j;
    }
}

void godown()
{
    yc = (yc * 2) % M;
    yc = (yc - C(i, j) + M) % M;
    ++i;
}

void solv()
{
    scanf("%d%lld", &n, &T);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + t[i];

    int ans = 0;

    int z = rf[2];

    int psans = 0;
    for (int i = 0; i <= n; ++i)
    {
        int ysans = 0;

        ll u = max(-1LL, T - p[i] - t[i + 1]);
        if (i == n)
            u = -1;
        if (-1 <= u && u <= i - 1)
        {
            go(u);
            ysans = (ysans + ast(2, i)) % M;;
            ysans = (ysans - yc + M) % M;
        }

        u = max(-1LL, T - p[i] - t[i + 1] - 1);
        if (i == n)
            u = -1;
        if (-1 <= u && u <= i - 1)
        {
            go(u);
            ysans = (ysans + ast(2, i)) % M;;
            ysans = (ysans - yc + M) % M;
        }

        ysans = (ysans - psans + M) % M;

        ans = (ans + (ysans * 1LL * i) % M * z) % M;

        psans = (psans + ysans) % M;
        psans = (psans * 2) % M;

        z = (z * 1LL * rf[2]) % M;
        godown();
    }

    printf("%d\n", ans);
    return;

    int tans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        ll yt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                yt += t[i + 1];
            }
            else
            {
                yt += (t[i + 1] + 1);
            }
            if (yt > T)
            {
                q = i;
                break;
            }
        }
        if (yt <= T)
            q = n;
        tans = (tans + q * 1LL * ast(ast(2, n), M - 2)) % M;
    }
    printf("%d\n", tans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}