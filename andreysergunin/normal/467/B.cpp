#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long n, k, m, a[2000], b[2000], ans, i;
    ans = 0;
    cin >> n >> m >> k;
    for (i = 0; i < m + 1; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        b[i] = a[i] ^ a[m];
    for (i = 0; i < m; i++)
    {
        long j, t = 0;
        j = b[i];
        while (j > 0)
        {
            t += j % 2;
            j = j / 2;
        }
        if (t <= k)
            ans++;
    }
    cout << ans;
    return 0;
}