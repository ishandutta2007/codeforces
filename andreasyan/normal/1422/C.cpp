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
const int N = 100005;
const int M = 1000000007;

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
char aa[N], a[N];

int ss[N];

void solv()
{
    scanf("%s", aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1] - '0';
    for (int i = n; i >= 1; --i)
    {
        ss[i] = (ss[i + 1] + ast(10, n - i)) % M;
    }
    int ans = 0;
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        p = ((p * 1LL * 10) + a[i]) % M;
        ans = (ans + (p * 1LL * ss[i + 1])) % M;
    }
    int s = 0;
    for (int i = n; i >= 1; --i)
    {
        s = (s + (a[i] * 1LL * ast(10, n - i))) % M;
        ans = (ans + (s * 1LL * (i - 1))) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}