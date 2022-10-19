#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int B = 330;

int n, m, qq;
long long a[N];
int s[N];
int ss[N];
vector<int> v[N];
vector<int> vv[N];

int u[N];
int uu[N];
bool so(const int a, const int b)
{
    return s[a] > s[b];
}

int b;
int q[N][B];

long long ans[B];
long long aa[B];

int main()
{
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &s[i]);
        for (int j = 0; j < s[i]; ++j)
        {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 1; i <= m; ++i)
        u[i] = i;
    sort(u + 1, u + m + 1, so);
    for (int i = 1; i <= m; ++i)
        uu[u[i]] = i;
    for (int i = 1; i <= m; ++i)
    {
        vv[i] = v[u[i]];
        ss[i] = s[u[i]];
    }
    for (int i = 1; i <= m; ++i)
    {
        v[i] = vv[i];
        s[i] = ss[i];
    }
    b = min(m, 320);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            for (int k = 1; k <= b; ++k)
            {
                if (binary_search(v[k].begin(), v[k].end(), x))
                    ++q[i][k];
            }
        }
    }
    for (int i = 1; i <= B; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            ans[i] += a[x];
        }
    }
    while (qq--)
    {
        char ty;
        scanf(" %c", &ty);
        if (ty == '?')
        {
            int k;
            scanf("%d", &k);
            k = uu[k];
            if (k <= b)
            {
                printf("%lld\n", ans[k]);
            }
            else
            {
                long long ans = 0;
                for (int j = 0; j < v[k].size(); ++j)
                {
                    int x = v[k][j];
                    ans += a[x];
                }
                for (int i = 1; i <= b; ++i)
                {
                    ans += q[k][i] * aa[i];
                }
                printf("%lld\n", ans);
            }
        }
        else
        {
            int k, y;
            scanf("%d%d", &k, &y);
            k = uu[k];
            if (k <= b)
            {
                aa[k] += y;
                for (int i = 1; i <= b; ++i)
                {
                    ans[i] += (y * 1LL * q[k][i]);
                }
            }
            else
            {
                for (int j = 0; j < v[k].size(); ++j)
                {
                    int x = v[k][j];
                    a[x] += y;
                }
                for (int i = 1; i <= b; ++i)
                {
                    ans[i] += (y * 1LL * q[k][i]);
                }
            }
        }
    }
    return 0;
}