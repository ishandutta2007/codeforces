#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
#define int long long
const int N = 200005;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int f[N], rf[N];

void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * (i + 1)) % M;
}

int C(int n, int k)
{
    return (((f[n] * rf[k]) % M) * rf[n - k]) % M;
}

int food, wine, h;

void solv()
{
    cin >> food >> wine >> h;
    ++h;
    if (wine == 0)
    {
        cout << 1 << endl;
        return;
    }
    if (food == 0)
    {
        if (wine >= h)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }
    int ans = 0;
    int ansb = 0;
    for (int qw = 1; qw <= wine; ++qw)
    {
        for (int qf = max(1LL, qw - 1); qf <= min(food, qw + 1); ++qf)
        {
            ansb = (ansb + C(wine - 1, qw - 1) * C(food - 1, qf - 1)) % M;
            if (qf == qw)
                ansb = (ansb + C(wine - 1, qw - 1) * C(food - 1, qf - 1)) % M;
            if (wine - h * qw >= 0)
            {
                ans = (ans + C(wine - h * qw + qw - 1, qw - 1) * C(food - 1, qf - 1)) % M;
                if (qf == qw)
                    ans = (ans + C(wine - h * qw + qw - 1, qw - 1) * C(food - 1, qf - 1)) % M;
            }
        }
    }
    //cout << ans << endl;
    ans = (ans * 1LL * ast(ansb, M - 2)) % M;
    cout << ans << endl;
}

int32_t main()
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