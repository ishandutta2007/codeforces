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
const int N = 103, M = 1000000007;

int n, k;
int a[N];

int q0, q1;

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

struct ban
{
    int a[N][N];
    ban()
    {
        memset(a, 0, sizeof a);
    }
};

ban operator*(const ban& a, const ban& b)
{
    ban ans;
    for (int i = 0; i <= q0; ++i)
    {
        for (int j = 0; j <= q0; ++j)
        {
            for (int k = 0; k <= q0; ++k)
            {
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * 1LL * b.a[k][j]) % M;
            }
        }
    }
    return ans;
}
ban ast(ban x, int n)
{
    ban ans;
    for (int i = 0; i <= q0; ++i)
        ans.a[i][i] = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            ++q0;
        else
            ++q1;
    }
    ban x;
    for (int i = 0; i <= q0; ++i)
    {
        int j = (q1 - i);
        if (!(0 <= j && j <= q1))
            continue;
        int m1 = i * (q1 - j);
        int p1 = (q0 - i) * j;
        int mn = (n * (n - 1) / 2) - m1 - p1;
        m1 = (m1 * 1LL * ast((n * (n - 1) / 2), M - 2)) % M;
        p1 = (p1 * 1LL * ast((n * (n - 1) / 2), M - 2)) % M;
        mn = (mn * 1LL * ast((n * (n - 1) / 2), M - 2)) % M;
        x.a[i - 1][i] = m1;
        x.a[i + 1][i] = p1;
        x.a[i][i] = mn;
    }
    x = ast(x, k);
    int u = 0;
    for (int i = 1; i <= q0; ++i)
    {
        if (a[i] == 1)
            ++u;
    }
    printf("%d\n", x.a[0][u]);
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