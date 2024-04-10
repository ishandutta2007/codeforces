#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
    if (n < k)
        return 0;
    return (f[n] * 1LL * ((rf[k] * 1LL * rf[n - k]) % M)) % M;
}

int n;
int u[N], uu[N];
vector<vector<int> > a, b;

int c[100][100];

int main()
{
    pre();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &u[i]);
    while (1)
    {
        if ((n - 1) % 4 == 0)
        {
            int ans = 0;
            for (int i = 0; i < n; ++i)
            {
                if (i % 2 == 0)
                    ans = (ans + (C((n - 1) / 2, i / 2) * 1LL * u[i + 1]) % M) % M;
            }
            printf("%d\n", ans);
            return 0;
        }
        if ((n - 1) % 4 == 1)
        {
            int ans = 0;
            for (int i = 0; i < n; ++i)
            {
                ans = (ans + (C((n - 1) / 2, i / 2) * 1LL * u[i + 1]) % M) % M;
            }
            printf("%d\n", ans);
            return 0;
        }
        bool z = true;
        for (int i = 1; i <= n - 1; ++i)
        {
            if (z)
                uu[i] = (u[i] + u[i + 1]) % M;
            else
                uu[i] = (u[i] - u[i + 1] + M) % M;
            z ^= true;
        }
        --n;
        for (int i = 1; i <= n; ++i)
            u[i] = uu[i];
        while (!z)
        {
            for (int i = 1; i <= n - 1; ++i)
            {
                if (z)
                    uu[i] = (u[i] + u[i + 1]) % M;
                else
                    uu[i] = (u[i] - u[i + 1] + M) % M;
                z ^= true;
            }
            --n;
            for (int i = 1; i <= n; ++i)
                u[i] = uu[i];
        }
    }
    for (int i = 0; i < 100; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    for (n = 1; n <= 20; ++n)
    {
    a.clear();
    b.clear();
    for (int i = 1; i <= n; ++i)
    {
        vector<int> v;
        v.assign(n, 0);
        v[i - 1]++;
        a.push_back(v);
    }
    bool z = true;
    for (int m = n; m > 1; --m)
    {
        b.clear();
        for (int i = 0; i < m - 1; ++i)
        {
            vector<int> v;
            v.assign(n, 0);
            if (z)
            {
                for (int j = 0; j < n; ++j)
                    v[j] = a[i][j] + a[i + 1][j];
            }
            else
            {
                for (int j = 0; j < n; ++j)
                    v[j] = a[i][j] - a[i + 1][j];
            }
            b.push_back(v);
            z ^= true;
        }
        a = b;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", a[0][i]);
    printf("\n");
    if ((n - 1) % 4 == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                printf("%d ", c[(n - 1) / 2][i / 2]);
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    else if ((n - 1) % 4 == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", c[(n - 1) / 2][i / 2]);
        }
        printf("\n");
    }
    }
    return 0;
}