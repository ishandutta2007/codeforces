#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;
const long long INF = 100000008000000009;

int n;
long long g1, g2;
int a[N];

long long ans = INF;

long long p[N], s[N];

set<int> ss;
void solvv(int x)
{
    if (ss.find(x) != ss.end())
        return;
    ss.insert(x);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x == 0)
            p[i] = p[i - 1];
        else
        {
            if ((a[i] - 1) % x == 0 || (a[i] + 1) % x == 0)
                p[i] = p[i - 1] + g2;
            else
                p[i] = INF;
        }
        p[i] = min(p[i], INF);
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] % x == 0)
            s[i] = s[i + 1];
        else
        {
            if ((a[i] - 1) % x == 0 || (a[i] + 1) % x == 0)
                s[i] = s[i + 1] + g2;
            else
                s[i] = INF;
        }
        s[i] = min(s[i], INF);
    }
    ans = min(ans, p[n]);
    long long minu = INF;
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu, p[i - 1] - i * g1);
        ans = min(ans, s[i + 1] + i * g1 + g1 + minu);
    }
}

void solv(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            solvv(i);
        }
    }
    if (x > 1)
        solvv(x);
}

void solv()
{
    scanf("%d%lld%lld", &n, &g1, &g2);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    solv(a[1] - 1);
    solv(a[1]);
    solv(a[1] + 1);
    solv(a[n] - 1);
    solv(a[n]);
    solv(a[n] + 1);
    printf("%lld\n", ans);
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