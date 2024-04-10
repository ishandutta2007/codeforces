#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 7;
const long long M = 1000000007;

struct ban
{
    int n;
    long long a[N][N];
    ban()
    {
        n = 0;
        memset(a, 0, sizeof a);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban ans;
    ans.n = a.n;
    for (int i = 1; i <= a.n; ++i)
    {
        for (int j = 1; j <= a.n; ++j)
        {
            for (int k = 1; k <= a.n; ++k)
            {
                ans.a[i][j] += (a.a[i][k] * b.a[k][j]);
                ans.a[i][j] %= (M - 1);
            }
        }
    }
    return ans;
}

ban ast(ban x, long long n)
{
    ban ans;
    ans.n = x.n;
    for (int i = 1; i <= ans.n; ++i)
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

long long astt(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

long long n, f1, f2, f3, c;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> f1 >> f2 >> f3 >> c;
    ban t;
    t.n = 3;
    t.a[2][1] = 1;
    t.a[3][2] = 1;
    t.a[1][3] = t.a[2][3] = t.a[3][3] = 1;
    /*for (int i = 1; i <= t.n; ++i)
    {
        for (int j = 1; j <= t.n; ++j)
        {
            printf("%d ", t.a[i][j]);
        }
        printf("\n");
    }*/
    t = ast(t, n - 3);
    long long uf1 = t.a[1][3];
    long long uf2 = t.a[2][3];
    long long uf3 = t.a[3][3];
    t = ban();
    t.n = 5;
    t.a[2][1] = 1;
    t.a[3][2] = 1;
    t.a[1][3] = t.a[2][3] = t.a[3][3] = t.a[4][3] = t.a[5][3] = 1;
    t.a[4][4] = t.a[5][4] = 1;
    t.a[5][5] = 1;
    /*for (int i = 1; i <= t.n; ++i)
    {
        for (int j = 1; j <= t.n; ++j)
        {
            printf("%d ", t.a[i][j]);
        }
        printf("\n");
    }*/
    t = ast(t, n - 3);
    long long uc = (t.a[5][3] * 2) % (M - 1);
    long long ans = (((((astt(f1, uf1) * astt(f2, uf2)) % M) * astt(f3, uf3)) % M) * astt(c, uc)) % M;
    cout << ans << endl;
    return 0;
}