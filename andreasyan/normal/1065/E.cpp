#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, M = 998244353;

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

int n, m, A;
int b[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &A);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
    }
    int r2 = ast(2, M - 2);
    int ans = ast(A, ((n / 2) - b[m]) * 2 + (n % 2));
    for (int i = 1; i <= m; ++i)
    {
        int u = ast(A, b[i] - b[i - 1]);
        u = (u * 1LL * (u + 1)) % M;
        u = (u * 1LL * r2) % M;
        ans = (ans * 1LL * u) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}