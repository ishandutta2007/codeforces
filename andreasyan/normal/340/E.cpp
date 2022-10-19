#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;
const int M = 1000000007;

int c[N][N];
int f[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

int n;
int a[N];

bool cc[N];

vector<int> u, v;

int main()
{
    pre();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] != -1)
        {
            cc[a[i]] = true;
        }
        else
        {
            u.push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!cc[i])
            v.push_back(i);
    }
    int q = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (binary_search(u.begin(), u.end(), v[i]))
            ++q;
    }
    int ans = 0;
    for (int i = 0; i <= q; ++i)
    {
        if (i % 2 == 0)
            ans = (ans + (c[q][i] * 1LL * f[(int)v.size() - i]) % M) % M;
        else
            ans = (ans - (c[q][i] * 1LL * f[(int)v.size() - i]) % M + M) % M;
    }
    printf("%d\n", ans);
    return 0;
}