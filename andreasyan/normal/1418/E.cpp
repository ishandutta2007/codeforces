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
const ll M = 998244353;

struct ban
{
    ll x;
    ban()
    {
        x = 0;
    }
    ban(ll x)
    {
        this->x = x % M;
    }
};

ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban ast(ban x, int n)
{
    ban ans(1);
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

ban f[N], rf[N];
void pre()
{
    f[0] = ban(1);
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * ban(i);
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = rf[i + 1] * ban(i + 1);
}

int n, qq;
int d[N];

ban p[N];

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + ban(d[i]);
    while (qq--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int q1 = lower_bound(d + 1, d + n + 1, b) - d - 1;
        int q2 = n - q1;
        if (a > q2)
        {
            printf("0\n");
            continue;
        }

        ban ans;

        ban u;
        u = f[q2];
        u = u * ban(q2 + 1 - a);
        u = u * f[n] * rf[n - (q1 - 1)];
        u = u * rf[n];

        ans = ans + u * p[q1];

        u = ban(0);
        --q2;
        u = f[q2];
        u = u * ban(q2 + 1 - a);
        u = u * f[n] * rf[n - q1];
        u = u * rf[n];
        ++q2;

        ans = ans + u * (p[n] - p[q1]);

        printf("%lld\n", ans.x);
    }
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