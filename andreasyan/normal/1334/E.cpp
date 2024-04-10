#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
const int N = 1003;

int f[N];
int ast[N][N];
int c[N][N];
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        if (i == 0)
            f[i] = 1;
        else
            f[i] = (f[i - 1] * 1LL * i) % M;
        ast[i][0] = 1;
        for (int j = 1; j < N; ++j)
            ast[i][j] = (ast[i][j - 1] * 1LL * f[i]) % M;
    }
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

long long n;
vector<long long> v;

int main()
{
    pre();
    scanf("%I64d", &n);
    for (long long i = 2; i * i <= n; ++i)
    {
        if ((n % i) == 0)
        {
            v.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
        v.push_back(n);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        long long x, y;
        scanf("%I64d%I64d", &x, &y);
        vector<int> xx, yy;
        xx.assign(v.size(), 0);
        yy.assign(v.size(), 0);
        for (int i = 0; i < v.size(); ++i)
        {
            while (x % v[i] == 0)
            {
                ++xx[i];
                x /= v[i];
            }
            while (y % v[i] == 0)
            {
                ++yy[i];
                y /= v[i];
            }
        }
        int ans = 1;
        int q = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (xx[i] - yy[i] > 0)
            {
                ans = (ans * 1LL * c[q + (xx[i] - yy[i])][xx[i] - yy[i]]) % M;
                q += (xx[i] - yy[i]);
            }
        }
        q = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (xx[i] - yy[i] < 0)
            {
                ans = (ans * 1LL * c[q + (yy[i] - xx[i])][yy[i] - xx[i]]) % M;
                q += (yy[i] - xx[i]);
            }
        }
        printf("%d\n", ans);
        continue;
        vector<int> vv;
        for (int i = 0; i < v.size(); ++i)
        {
            if (xx[i] - yy[i] < 0)
                vv.push_back(xx[i] - yy[i]);
        }
        sort(vv.begin(), vv.end());
        for (int i = 0; i < vv.size(); ++i)
        {
            if (!i || vv[i] == vv[i - 1])
                continue;
            ans = (ans * 1LL * ast[i][vv[i] - vv[i - 1]]) % M;
        }
        if (!vv.empty())
            ans = (ans * 1LL * ast[vv.size()][0 - vv.back()]);
        vv.clear();
        for (int i = 0; i < v.size(); ++i)
        {
            if (xx[i] - yy[i] > 0)
                vv.push_back(xx[i] - yy[i]);
        }
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());
        for (int i = 0; i < vv.size(); ++i)
        {
            if (!i || vv[i] == vv[i - 1])
                continue;
            ans = (ans * 1LL * ast[i][vv[i - 1] - vv[i]]) % M;
        }
        if (!vv.empty())
            ans = (ans * 1LL * ast[vv.size()][vv.back() - 0]);
        printf("%d\n", ans);
    }
    return 0;
}