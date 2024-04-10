#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 22;

int n, m;
int a[N];

int dp[(1 << N)];
pair<int, int> p[(1 << N)];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        a[x] |= (1 << y);
        a[y] |= (1 << x);
    }
    for (int i = 0; i < n; ++i)
        a[i] |= (1 << i);
    for (int x = 0; x < (1 << n); ++x)
    {
        dp[x] = N * N;
    }
    for (int x = 0; x < (1 << n); ++x)
    {
        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                if ((a[i] & x) != x)
                {
                    z = false;
                    break;
                }
            }
        }
        if (z)
            dp[x] = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                if (dp[x] + 1 < dp[(x | a[i])])
                {
                    dp[(x | a[i])] = dp[x] + 1;
                    p[(x | a[i])] = m_p(i, x);
                }
            }
        }
    }
    vector<int> v;
    int x = (1 << n) - 1;
    while (dp[x])
    {
        v.push_back(p[x].first);
        x = p[x].second;
    }
    reverse(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i] + 1);
    printf("\n");
    return 0;
}