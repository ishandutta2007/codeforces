#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const long long INF = 100005000000009;

int n;
long long k;
int a[N];

long long p[N];
vector<long long> v;

int t[N];
void ubd(int x)
{
    while (x < N)
    {
        ++t[x];
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

bool stg(long long x)
{
    memset(t, 0, sizeof t);
    ubd(lower_bound(v.begin(), v.end(), p[0]) - v.begin() + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += qry(upper_bound(v.begin(), v.end(), p[i] - x) - v.begin());
        if (ans >= k)
            return true;
        ubd(lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1);
    }
    return false;
}

void solv()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 0; i <= n; ++i)
        v.push_back(p[i]);
    sort(v.begin(), v.end());
    long long l = -INF, r = INF;
    long long ans;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%I64d\n", ans);
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