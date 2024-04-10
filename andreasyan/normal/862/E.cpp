#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const long long INF = 1000000009000000009;

int n, m, q;
int a[N], b[N];

long long s[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    for (int i = m; i >= 1; --i)
    {
        s[i] = s[i + 2] + b[i];
    }
    vector<long long> v;
    for (int i = 1; i <= m - n + 1; ++i)
    {
        int j1 = i + n, j2 = i + n;
        while (j1 % 2 != i % 2)
            ++j1;
        while (j2 % 2 != (i + 1) % 2)
            ++j2;
        v.push_back(s[i] - s[j1] - s[i + 1] + s[j2]);
    }
    sort(v.begin(), v.end());
    long long s = 0;
    for (int i = 1; i <= n; i += 2)
        s += a[i];
    for (int i = 2; i <= n; i += 2)
        s -= a[i];
    long long ans = INF;
    int j = upper_bound(v.begin(), v.end(), s) - v.begin();
    if (j < v.size())
        ans = min(ans, v[j] - s);
    --j;
    if (j >= 0)
        ans = min(ans, s - v[j]);
    printf("%I64d\n", ans);
    while (q--)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if ((r - l + 1) % 2 == 1)
        {
            if (l % 2 == 1)
                s += x;
            else
                s -= x;
        }
        long long ans = INF;
        int j = upper_bound(v.begin(), v.end(), s) - v.begin();
        if (j < v.size())
            ans = min(ans, v[j] - s);
        --j;
        if (j >= 0)
            ans = min(ans, s - v[j]);
        printf("%I64d\n", ans);
    }
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