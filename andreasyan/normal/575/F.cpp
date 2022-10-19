#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;
const long long INF = 10000000090004;

int n;
int x;
int l[N], r[N];

int z;
vector<int> v;
map<int, int> mp;
int rmp[N + N];

long long dp[N + N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    v.push_back(x);
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
            rmp[z] = v[i];
        }
    }
    x = mp[x];
    for (int i = 1; i <= n; ++i)
    {
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
    }
    for (int j = 1; j <= z; ++j)
        dp[j] = INF;
    dp[x] = 0;
    for (int i = 1; i <= n; ++i)
    {
        long long minu = INF;
        for (int j = 1; j <= z; ++j)
        {
            if (j)
                minu += (rmp[j] - rmp[j - 1]);
            minu = min(minu, dp[j]);
            dp[j] = minu;
        }
        minu = INF;
        for (int j = z; j >= 1; --j)
        {
            if (j < z)
                minu += (rmp[j + 1] - rmp[j]);
            minu = min(minu, dp[j]);
            dp[j] = minu;
        }
        for (int j = 1; j <= z; ++j)
        {
            if (l[i] <= j && j <= r[i])
                continue;
            if (j < l[i])
                dp[j] += (rmp[l[i]] - rmp[j]);
            else
                dp[j] += (rmp[j] - rmp[r[i]]);
        }
    }
    long long ans = INF;
    for (int j = 1; j <= z; ++j)
        ans = min(ans, dp[j]);
    printf("%I64d\n", ans);
    return 0;
}