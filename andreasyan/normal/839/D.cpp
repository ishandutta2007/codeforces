#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;
const int M = 1000000007;

int n;
int q[N];

int ast[N];

bool c[N];
int u[N];

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    int ans = 0;
    for (int i = 2; i < N; ++i)
    {
        for (int j = i + i; j < N; j += i)
            u[j] = (u[j] + i - u[i] + M) % M;
        int qq = 0;
        for (int j = i; j < N; j += i)
            qq += q[j];
        if (qq)
        {
            ans += (((qq * 1LL * ast[qq - 1]) % M) * i) % M;
            ans %= M;
        }
        if (qq)
        {
            ans = ans - (((qq * 1LL * ast[qq - 1]) % M) * u[i]) % M + M;
            ans %= M;
        }
    }
    printf("%d\n", ans);
    return 0;
}