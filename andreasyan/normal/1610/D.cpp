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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

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

int n;
int a[N];

const int m = 30;
int q[m];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int x = 1;
        int j = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            x *= 2;
            ++j;
        }
        a[i] = x;
        q[j]++;
    }

    int ans = 0;
    /*for (int x = 1; x < (1 << n); ++x)
    {
        ll s = 0;
        int g = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                s = (s + a[i + 1]) * 1LL * a[i + 1] - a[i + 1]);
                g = gcd(g, a[i + 1]);
            }
        }
        s /= 2;

        if (s % g == 0)
        {
            ++ans;
            continue;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << a[i + 1] << ' ';
            }
            cout << "\n";
        }
    }
    cout << ans << "\n";
    return;*/

    ans = (ast(2, n) - 1 + M) % M;
    for (int i = 1; i < m; ++i)
    {
        if (q[i])
        {
            int yans = ast(2, q[i] - 1) % M;
            for (int j = i + 1; j < m; ++j)
                yans = (yans * 1LL * ast(2, q[j])) % M;
            ans = (ans - yans + M) % M;
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}