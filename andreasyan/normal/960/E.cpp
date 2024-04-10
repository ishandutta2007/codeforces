#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
long long M = 1000000007;

int n;
long long u[N];
long long ur[N];
vector<int> a[N];

int q[N][2];

void dfs0(int x, int p)
{
    q[x][0] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x][0] += q[h][1];
        q[x][1] += q[h][0];
    }
}

int ans;

void dfs1(int x, int p, int qp0, int qp1)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            ans += (((qp1 * u[x]) % M) * (n - qp1 - qp0)) % M;
            ans %= M;
            ans += (((qp0 * ur[x]) % M) * (n - qp1 - qp0)) % M;
            ans %= M;
            continue;
        }
        ans += (((q[h][1] * u[x]) % M) * (n - q[h][0] - q[h][1])) % M;
        ans %= M;
        ans += (((q[h][0] * ur[x]) % M) * (n - q[h][0] - q[h][1])) % M;
        ans %= M;
    }
    ans += (u[x] * n) % M;
    ans %= M;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs1(h, x, qp1 + q[x][0] - q[h][1], qp0 + q[x][1] - q[h][0]);
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%I64d", &u[i]);
        u[i] = (M + u[i]) % M;
        ur[i] = (M - u[i]) % M;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs0(1, 1);
    dfs1(1, 1, 0, 0);
    printf("%d\n", ans);
    return 0;
}