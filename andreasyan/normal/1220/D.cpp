#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
long long a[N];

const int m = 100;
vector<long long> v[m];

int main()
{
    /*for (int i = 2; i <= 60; i += 2)
    {
        for (int j = 2; j <= 60; j += 2)
        {
            int k = i / gcd(i, j) * j;
            if ((k / i + k / j) % 2 == 0)
                cout << i << ' ' << j << endl;
        }
    }*/
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        long long x;
        scanf("%lld", &x);
        long long xx = x;
        int q = 0;
        while (x % 2 == 0)
        {
            x /= 2;
            ++q;
        }
        v[q].push_back(xx);
    }
    int maxu = 0;
    for (int i = 0; i < m; ++i)
    {
        if (v[i].size() > maxu)
            maxu = v[i].size();
    }
    for (int i = 0; i < m; ++i)
    {
        if (v[i].size() == maxu)
        {
            printf("%d\n", n - v[i].size());
            for (int j = 0; j < m; ++j)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < v[j].size(); ++k)
                {
                    printf("%lld ", v[j][k]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}