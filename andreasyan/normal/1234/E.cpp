#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int a[N];

vector<int> v[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < m; ++i)
    {
        if (a[i] == a[i + 1])
            continue;
        v[a[i]].push_back(a[i + 1]);
        v[a[i + 1]].push_back(a[i]);
    }
    long long ans = 0;
    for (int i = 1; i < m; ++i)
    {
        ans += (abs(a[i] - a[i + 1]));
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int h = v[i][j];
            if (i < h)
            {
                ans -= (h - i);
                ans += (h - 1);
            }
            else
            {
                ans -= (i - h - 1);
                ans += (h);
            }
        }
        printf("%lld ", ans);
        for (int j = 0; j < v[i].size(); ++j)
        {
            int h = v[i][j];
            if (i < h)
            {
                ans -= (h - 1);
                ans += (h - i - 1);
            }
            else
            {
                ans -= (h);
                ans += (i - h);
            }
        }
    }
    printf("\n");
    return 0;
}