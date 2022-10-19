#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, M = 1000000007;

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

int n;
char a[N], b[N];

int yans = 1;

int qq;
int q[26];

void ubd(int x, int y)
{
    yans = (yans * 1LL * rf[qq]) % M;
    yans = (yans * 1LL * f[q[x]]) % M;
    qq += y;
    q[x] += y;
    yans = (yans * 1LL * f[qq]) % M;
    yans = (yans * 1LL * rf[q[x]]) % M;
}

void solv()
{
    scanf(" %s %s", a, b);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        ubd(a[i] - 'a', 1);
    }
    int ans = 0;
    int s;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            s = i;
            break;
        }
        ubd(a[i] - 'a', -1);
    }
    for (char u = a[s] + 1; u < b[s]; ++u)
    {
        if (q[u - 'a'])
        {
            ubd(u - 'a', -1);
            ans = (ans + yans) % M;
            ubd(u - 'a', 1);
        }
    }
    for (int i = s; i < n - 1; ++i)
    {
        ubd(a[i] - 'a', -1);
        for (char u = a[i + 1] + 1; u <= 'z'; ++u)
        {
            if (q[u - 'a'])
            {
                ubd(u - 'a', -1);
                ans = (ans + yans) % M;
                ubd(u - 'a', 1);
            }
        }
    }
    for (int i = s; i < n - 1; ++i)
        ubd(a[i] - 'a', 1);
    for (int i = s; i < n - 1; ++i)
    {
        if (!q[b[i] - 'a'])
            break;
        ubd(b[i] - 'a', -1);
        for (char u = 'a'; u < b[i + 1]; ++u)
        {
            if (q[u - 'a'])
            {
                ubd(u - 'a', -1);
                ans = (ans + yans) % M;
                ubd(u - 'a', 1);
            }
        }
    }
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