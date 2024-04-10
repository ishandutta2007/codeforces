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
const int N = 100;

bool dp[N][N];

bool D(int n, int q)
{
    assert(n >= 1);
    if (q < 0)
        return false;
    if (q > n)
        return false;
    if (n < N)
        return dp[n][q];

    if (n % 2 == 0)
        return false;

    int x = n + 1;
    while (x % 2 == 0)
        x /= 2;

    if (x == 1)
    {
        if (q == 0)
            return true;
        if (q == 1)
            return false;
        return (q < n / 2);
    }
    if (q == 0)
        return false;
    return (q < n / 2);
}

void pre()
{
    dp[1][0] = true;
    for (int n = 2; n < N; ++n)
    {
        for (int q1 = 1; q1 < n - 1; ++q1)
        {
            int q2 = n - 1 - q1;
            for (int i = 0; i <= q1; ++i)
            {
                if (!dp[q1][i])
                    continue;
                for (int j = 0; j <= q2; ++j)
                {
                    if (!dp[q2][j])
                        continue;
                    if (max(q1, q2) >= min(q1, q2) * 2)
                        dp[n][i + j + 1] = true;
                    else
                        dp[n][i + j] = true;
                }
            }
        }
    }

    /*for (int n = 1; n < N; ++n)
    {
        if (n <= 9)
            cout << ' ' << n << ' ';
        else
            cout << n << ' ';
        for (int q = 0; q <= n; ++q)
            cout << dp[n][q];
        cout << "\n";
    }
    exit(0);*/
}

int z;
int ans[100005];

void rec(int n, int q, int x)
{
    assert(D(n, q));
    if (n == 1)
        return;

    int h1 = ++z;
    int h2 = ++z;
    ans[h1] = ans[h2] = x;

    if (q >= 2 || q == 0)
    {
        bool z = false;
        for (int n1 = max(1, n / 2 - 5); n1 <= min(n - 2, n / 2 + 5); ++n1)
        {
            int n2 = n - 1 - n1;
            for (int q1 = max(0, q / 2 - 5); q1 <= min(n1, q / 2 + 5); ++q1)
            {
                int q2 = q - q1;
                bool t = (max(n1, n2) >= 2 * min(n1, n2));
                if (D(n1, q1 - t) && D(n2, q2))
                {
                    rec(n1, q1 - t, h1);
                    rec(n2, q2, h2);
                    z = true;
                    break;
                }
            }
            if (z)
                break;
        }
        if (!z)
        {
            for (int n1 = 1; n1 <= min(n - 2, 10); ++n1)
            {
                int n2 = n - 1 - n1;
                for (int q1 = 0; q1 <= n1; ++q1)
                {
                    int q2 = q - q1;
                    bool t = (max(n1, n2) >= 2 * min(n1, n2));
                    if (D(n1, q1) && D(n2, q2 - t))
                    {
                        rec(n1, q1, h1);
                        rec(n2, q2 - t, h2);
                        z = true;
                        break;
                    }
                }
                if (z)
                    break;
            }
        }
        assert(z);
    }
    else if (q == 1)
    {
        bool z = false;
        for (int n1 = 1; n1 <= n - 2; n1 = n1 * 2 + 1)
        {
            int n2 = n - 1 - n1;
            bool t = (max(n1, n2) >= 2 * min(n1, n2));
            if (D(n1, 0) && D(n2, 1 - t))
            {
                rec(n1, 0, h1);
                rec(n2, 1 - t, h2);
                z = true;
                break;
            }
        }
        assert(z);
    }
}

void solv()
{
    int n, q;
    cin >> n >> q;

    if (!D(n, q))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    z = 1;
    rec(n, q, 1);
    for (int x = 1; x <= n; ++x)
        cout << ans[x] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    /*for (int n = 1; n <= 1000; ++n)
    {
        for (int q = 0; q <= n; ++q)
        {
            if (D(n, q))
            {
                z = 1;
                rec(n, q, 1);
            }
        }
    }*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}