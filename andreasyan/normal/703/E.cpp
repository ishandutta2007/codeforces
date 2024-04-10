#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003, M = 10004;
const long long INF = 1000000009000000009;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
long long k;
long long a[N], aa[N];

vector<long long> vv;
void prevv()
{
    long long kk = k;
    for (long long i = 2; i * i <= kk; ++i)
    {
        if (kk % i == 0)
        {
            vv.push_back(i);
            while (kk % i == 0)
                kk /= i;
        }
    }
    if (kk > 1)
        vv.push_back(kk);
}

vector<long long> v;

vector<long long> q[M];
void preq()
{
    for (int i = 0; i < v.size(); ++i)
    {
        long long x = v[i];
        q[i].assign(vv.size(), 1);
        for (int j = 0; j < vv.size(); ++j)
        {
            while (x % vv[j] == 0)
            {
                x /= vv[j];
                q[i][j] *= vv[j];
            }
        }
    }
}

long long gcdd(int i, int j)
{
    long long ans = 1;
    for (int k = 0; k < vv.size(); ++k)
    {
        ans *= min(q[i][k], q[j][k]);
    }
    return ans;
}

map<long long, int> mp;

pair<int, long long> minu[M];
int mini[M];

pair<int, long long> dp[N][M];
int p[N][M], pj[N][M];
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        aa[i] = gcd(a[i], k);
    }
    for (long long i = 1; i * i <= k; ++i)
    {
        if (k % i == 0)
        {
            v.push_back(i);
            if (i * i != k)
                v.push_back(k / i);
        }
    }
    sort(v.begin(), v.end());
    prevv();
    preq();
    for (int j = 0; j < v.size(); ++j)
        mp[v[j]] = j;
    ////////////////////////////////////////////////
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < v.size(); ++j)
            dp[i][j] = m_p(N, INF);
    }
    dp[0][0] = m_p(0, 0);
    for (int j = 0; j < v.size(); ++j)
    {
        minu[j] = dp[0][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        int ii;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j] == aa[i])
            {
                ii = j;
                break;
            }
        }
        for (int j = 0; j < v.size(); ++j)
        {
            int jj = v.size() - j - 1;
            long long u = v[j] * gcdd(ii, jj);
            int uu = mp[u];
            if (m_p(minu[j].first + 1, minu[j].second + a[i]) < dp[i][uu])
            {
                dp[i][uu] = m_p(minu[j].first + 1, minu[j].second + a[i]);
                p[i][uu] = mini[j];
                pj[i][uu] = j;
            }
        }
        for (int j = 0; j < v.size(); ++j)
        {
            if (dp[i][j] < minu[j])
            {
                minu[j] = dp[i][j];
                mini[j] = i;
            }
        }
    }
    pair<int, long long> minu = m_p(N, INF);
    if (k == 1)
    {
        for (int i = 1; i <= n; ++i)
            minu.second = min(minu.second, a[i]);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == minu.second)
            {
                printf("1\n");
                printf("%d\n", i);
                return 0;
            }
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu, dp[i][v.size() - 1]);
    }
    if (minu.second == INF)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i][v.size() - 1] == minu)
        {
            vector<int> ans;
            int j = v.size() - 1;
            while (i)
            {
                ans.push_back(i);
                int ii = p[i][j];
                int jj = pj[i][j];
                i = ii;
                j = jj;
            }
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}