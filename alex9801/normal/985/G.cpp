#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int bs = 632;

ull c2(int n)
{
    return 1LL * n * (n - 1) / 2;
}
ull sum(int l, int r)
{
    return 1LL * r * (r + 1) / 2 - 1LL * (l - 1) * l / 2;
}

vector<int> arr[200010];

int main()
{
    int n, m;
    ull a, b, c;
    scanf("%d%d%llu%llu%llu", &n, &m, &a, &b, &c);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    for(int i = 0; i < n; i++)
        sort(arr[i].begin(), arr[i].end());

    ull res0 = 0;
    for(int x = 0; x < n; x++)
    {
        res0 += a * x * c2(n - x - 1);
        res0 += b * x * x * (n - x - 1);
        res0 += c * x * c2(x);
    }

    ull res1 = 0;
    for(int x = 0; x < n; x++)
    {
        for(int y : arr[x])
        {
            if(y < x)
                continue;

            res1 += a * sum(0, x - 1) + (b * x + c * y) * x;
            res1 += b * sum(x + 1, y - 1) + (a * x + c * y) * (y - x - 1);
            res1 += c * sum(y + 1, n - 1) + (a * x + b * y) * (n - y - 1);
        }
    }

    ull res2 = 0;
    for(int x = 0; x < n; x++)
    {
        int sz = (int)arr[x].size();
        if(sz < 2)
            continue;

        int t = lower_bound(arr[x].begin(), arr[x].end(), x) - arr[x].begin();

        res2 += (a * c2(sz - t) + b * t * (sz - t) + c * c2(t)) * x;
        for(int i = 0; i < t; i++)
            res2 += (a * (sz - i - 1) + b * i) * arr[x][i];
        for(int i = t; i < sz; i++)
            res2 += (b * (sz - i - 1) + c * i) * arr[x][i];
    }

    ull res3 = 0;
    vector<int> big;
    for(int x = 0; x < n; x++)
    {
        int sz = (int)arr[x].size();
        if(sz >= bs)
        {
            big.push_back(x);
            continue;
        }
        if(sz < 2)
            continue;

        int t = lower_bound(arr[x].begin(), arr[x].end(), x) - arr[x].begin();

        for(int i = t; i < sz; i++)
        {
            int y = arr[x][i];
            for(int j = i + 1; j < sz; j++)
            {
                int z = arr[x][j];
                if(!binary_search(arr[y].begin(), arr[y].end(), z))
                    continue;

                res3 += a * x + b * y + c * z;
            }
        }
    }
    for(int y = 0; y < n; y++)
    {
        for(int z : arr[y])
        {
            if(z < y)
                continue;

            for(int x : big)
            {
                if(x > y)
                    break;

                if(!binary_search(arr[x].begin(), arr[x].end(), y))
                    continue;
                if(!binary_search(arr[x].begin(), arr[x].end(), z))
                    continue;

                res3 += a * x + b * y + c * z;
            }
        }
    }

    ull res = res0 - res1 + res2 - res3;
    printf("%llu\n", res);
    return 0;
}