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
const int N = 200005, M = 998244353;

int n;
int a[N];

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

void solv()
{
    scanf("%d", &n);
    a[0] = 1;
    int u[2] = {};
    for (int i = 0; i <= n; ++i)
    {
        a[i] = (a[i] + u[(i % 2)]) % M;
        u[1 - (i % 2)] = (u[1 - (i % 2)] + a[i]) % M;
    }
    printf("%d\n", (a[n] * 1LL * ast(ast(2, n), M - 2)) % M);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}