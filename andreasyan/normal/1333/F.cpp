#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;

//int ans[N];
//vector<int> vans[N];

int u[N];

int main()
{
    scanf("%d", &n);
    u[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (u[i])
            continue;
        u[i] = i;
        if (i * 1LL * i > n)
            continue;
        for (int j = i * i; j <= n; j += i)
        {
            if (u[j] == 0)
                u[j] = i;
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i / u[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
    /*for (int i = 1; i <= n; ++i)
        ans[i] = N;
    for (int x = 0; x < (1 << n); ++x)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                v.push_back(i + 1);
        }
        if (v.size() >= 2)
        {
            int maxu = 0;
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = i + 1; j < v.size(); ++j)
                {
                    maxu = max(maxu, gcd(v[i], v[j]));
                }
            }
            if (maxu < ans[v.size()])
            {
                ans[v.size()] = maxu;
                vans[v.size()] = v;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        printf("%d ", ans[i]);
        //for (int j = 0; j < vans[i].size(); ++j)
        //    printf("%d ", vans[i][j]);
        //printf("\n");
    }
    return 0;*/
}