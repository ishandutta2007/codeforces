#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, k;
long long a[N], aa[N];
long long b[N];

vector<int> v[N];

bool stg(long long x)
{
    if (x < 7)
        cout << "";
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i];
    for (int i = 1; i <= k; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        long long u = a[i] / b[i] + 1;
        if (u <= k)
        {
            if (x == 0)
                return false;
            v[u].push_back(i);
        }
    }
    int q = 0;
    for (int i = 1; i <= k; ++i)
    {
        ++q;
        for (int j = 0; j < v[i].size(); ++j)
        {
            int who = v[i][j];
            long long qq = -(a[who] - i * b[who]) / x;
            if (-(a[who] - i * b[who]) % x != 0)
                ++qq;
            if (q < qq)
                return false;
            q -= qq;
            a[who] += qq * x;
            long long u = a[who] / b[who] + 1;
            if (u <= k)
                v[u].push_back(who);
        }
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &k);
    --k;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        aa[i] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    long long l = 0, r = 1000000009000000009;
    long long ans = -1;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
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