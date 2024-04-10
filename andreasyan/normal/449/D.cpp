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
const int N = 1000006, m = 20, M = 1000000007;

int n;
int a[N];

int ast[N];

int q[(1 << m)];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
    for (int i = 1; i <= n; ++i)
    {
        q[a[i]]++;
    }
    for (int i = m - 1; i >= 0; --i)
    {
        for (int x = (1 << m) - 1; x >= 0; --x)
        {
            if ((x & (1 << i)))
            {
                q[(x ^ (1 << i))] += q[x];
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < (1 << m); ++x)
    {
        int qq = 0;
        for (int i = 0; i < m; ++i)
        {
            if ((x & (1 << i)))
            {
                ++qq;
            }
        }
        if (qq % 2 == 0)
            ans = (ans + (ast[q[x]] - 1 + M) % M) % M;
        else
            ans = (ans - (ast[q[x]] - 1 + M) % M + M) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}