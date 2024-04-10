#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

const int MAXN = 300000;

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, k, x;
    long long a[MAXN];
    int b[100];
    cin >> n >> k >> x;
    long long m = 1;
    for (int i = 0; i < k; ++i)
        m *= x;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        long long p = a[i];
        for (int j = 0; p != 0; p /= 2, ++j)
        {
            if (p % 2 == 1)
                ++b[j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        long long p = a[i];
        long long t = 1;
        long long ansi = 0;
        for (int j = 0; j <= 60; p /= 2, j++, t *= 2)
        {
            if (p % 2 == 1)
            {
                if (b[j] > 1)
                    ansi += t;
            }
            else
            {
                if (b[j] > 0)
                    ansi += t;
            }
        }
        ansi = ansi | (m * a[i]);
        ans = max(ans, ansi);
    }
    cout << ans;
    return 0;
}