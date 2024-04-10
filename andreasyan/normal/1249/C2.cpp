#include <bits/stdc++.h>
using namespace std;

long long n;

long long ast[100];
void pre()
{
    ast[0] = 1;
    for (int i = 1; i < 100; ++i)
        ast[i] = ast[i - 1] * 3;
}

void solv()
{
    scanf("%lld", &n);
    while (1)
    {
        long long nn = n;
        vector<long long> v;
        while (nn)
        {
            v.push_back(nn % 3);
            nn /= 3;
        }
        reverse(v.begin(), v.end());
        int m = v.size();
        bool z = false;
        for (int i = 0; i < m; ++i)
        {
            if (v[i] == 2)
            {
                for (int j = i; j < m; ++j)
                    n -= (ast[m - j - 1] * v[j]);
                n += (ast[m - i]);
                z = true;
                break;
            }
        }
        if (!z)
            break;
    }
    printf("%lld\n", n);
}

int main()
{
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}