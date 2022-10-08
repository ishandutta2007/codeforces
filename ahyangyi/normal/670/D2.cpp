#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    int tmp = 1000000000;
    for (int i = 0; i < n; i++)
    {
        int cur = b[i] / a[i];
        if (cur < tmp)
        {
            tmp = cur;
        }
    }
    int l = tmp, r = tmp + 1000000000;
    while (l < r)
    {
        int m = (l + (long long)r + 1) / 2;
        long long req = 0;
        for (int i = 0; i < n && req <= k; i ++)
        {
            if (b[i] / a[i] < m)
            {
                req += a[i] * (long long)m - b[i];
            }
        }
        if (req <= k)
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    std::cout << l << std::endl;
    return 0;
}