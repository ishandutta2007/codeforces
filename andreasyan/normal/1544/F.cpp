#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 25, M = 31607;

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

int n;
int a[N][N];

int ta[N];
int sa[N];

int b[N];

int sv;
int v[N];
int solvv()
{
    for (int i = 0; i < n; ++i)
    {
        ta[i] = 1;
        for (int j = 0; j < n; ++j)
        {
            ta[i] = (ta[i] * a[i][j]) % M;
        }
    }

    for (int j = 0; j < n; ++j)
    {
        sa[j] = 1;
        for (int i = 0; i < n; ++i)
        {
            sa[j] = (sa[j] * a[i][j]) % M;
        }
    }

    int ans = 1;
    for (int j = 0; j < n; ++j)
        ans = (ans * (1 - sa[j])) % M;
    ans = (1 - ans + M) % M;

    for (int x = 1; x < (1 << n); ++x)
    {
        int aans = 1;
        sv = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                aans = (aans * ta[i]) % M;
            }
            else
            {
                v[sv++] = i;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            b[j] = 1;
            for (int k = 0; k < sv; ++k)
            {
                b[j] = (b[j] * a[v[k]][j]) % M;
            }
        }
        int u = 1;
        for (int j = 0; j < n; ++j)
        {
            u = (u * (1 - b[j])) % M;
        }
        u = (u * aans) % M;
        if ((n - sv) % 2 == 1)
            ans = (ans + u) % M;
        else
            ans = (ans - u + M) % M;
    }
    return ans;
}

int ca[N][N];
void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
            a[i][j] = (a[i][j] * ast(10000, M - 2)) % M;
            ca[i][j] = a[i][j];
        }
    }
    /*n = 21;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = 5000;
            a[i][j] = (a[i][j] * ast(10000, M - 2)) % M;
            ca[i][j] = a[i][j];
        }
    }*/

    int ans = solvv();

    int yans = 1;
    for (int i = 0; i < n; ++i)
    {
        yans = (yans * a[i][i]) % M;
        a[i][i] = 1;
    }
    yans = (yans * (1 - solvv())) % M;
    ans = (ans + yans) % M;
    for (int i = 0; i < n; ++i)
        a[i][i] = ca[i][i];

    yans = 1;
    for (int i = 0; i < n; ++i)
    {
        yans = (yans * a[i][n - i - 1]) % M;
        a[i][n - i - 1] = 1;
    }
    yans = (yans * (1 - solvv())) % M;
    ans = (ans + yans) % M;
    for (int i = 0; i < n; ++i)
        a[i][n - i - 1] = ca[i][n - i - 1];

    yans = 1;
    for (int i = 0; i < n; ++i)
    {
        yans = (yans * a[i][i]) % M;
        if (i != n - i - 1)
            yans = (yans * a[i][n - i - 1]) % M;
        a[i][i] = a[i][n - i - 1] = 1;
    }
    yans = (yans * (1 - solvv())) % M;
    ans = (ans - yans + M) % M;

    ans = (ans + M) % M;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int ans = 0;
    for (int x = 0; x < (1 << 21); ++x)
    {
        int q = 0;
        for (int i = 0; i < 21; ++i)
        {
            if (!(x & (1 << i)))
                ++q;
        }
        ans += q * 21;
    }
    cout << ans << "\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}