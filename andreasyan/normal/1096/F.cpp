#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
const int M = 998244353;

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

int f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
}

int n;
int a[N];
bool c[N];

int p[N], s[N];

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        ++t[x];
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int ans;

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] != -1)
            c[a[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + !(c[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1] + !(c[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != -1)
        {
            ans = (ans + qry(a[i], n) * 1LL * f[p[n]]) % M;
            ubd(a[i]);
        }
    }
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != -1)
        {
            ans = (ans + (s[a[i]] * 1LL * q) % M * f[p[n] - 1]) % M;
        }
        else
        {
            ++q;
        }
    }
    q = 0;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] != -1)
        {
            ans = (ans + (p[a[i]] * 1LL * q) % M * f[p[n] - 1]) % M;
        }
        else
        {
            ++q;
        }
    }
    if (p[n] >= 2)
        ans = (ans + (((p[n] * 1LL * (p[n] - 1)) / 2) % M * ((p[n] * 1LL * (p[n] - 1)) / 2) % M) % M * f[p[n] - 2]) % M;
    ans = (ans * 1LL * ast(f[p[n]], M - 2)) % M;
    printf("%d\n", ans);
}

int main()
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