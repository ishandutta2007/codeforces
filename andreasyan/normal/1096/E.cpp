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
const int N = 5503, M = 998244353;

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

int c[N][N];

int f(int p, int s, int m)
{
    if (s < 0)
        return 0;
    if (m == 0)
    {
        if (s == 0)
            return 1;
        return 0;
    }
    if (m == -1)
    {
        if (s == 0 && p == 0)
            return 1;
        return 0;
    }
    if (p == 0)
    {
        if (s > 0)
            return 0;
        return 1;
    }

    int ans = 0;
    for (int i = 0; i <= p; ++i)
    {
        int yans = c[p][i];
        if (s - i * (m + 1) >= 0)
            yans = (yans * 1LL * c[s - i * (m + 1) + p - 1][p - 1]) % M;
        else
            break;
        if (i % 2 == 0)
            ans = (ans + yans) % M;
        else
            ans = (ans - yans + M) % M;
    }
    return ans;
}

int p, s, r;

void solv()
{
    cin >> p >> s >> r;

    int ans = 0;
    for (int x = r; x <= s; ++x)
    {
        for (int q = 1; q <= p; ++q)
        {
            int yans = (f(p - q, s - q * x, x - 1) * 1LL * ast(q, M - 2)) % M;
            yans = (yans * 1LL * ast(c[s - r + p - 1][p - 1], M - 2)) % M;
            yans = (yans * 1LL * c[p - 1][q - 1]) % M;
            ans = (ans + yans) % M;
        }
    }
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
    }

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}