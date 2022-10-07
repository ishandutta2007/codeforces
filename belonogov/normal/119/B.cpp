#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[1000];
int b[1000];
bool check[1000];


int main()
{
   int MIN=1e6, MAX=-1e6, q, n, i, j, k, m, sum, uk;
    cin >> n >> k;
    q = n / k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (i = 0; i < m; i++)
    {
        sum = 0;
        for (j = 0; j < q; j++)
        {
            cin >> b[j];
            check[b[j] - 1] = true;
            sum += a[b[j] - 1];
        }
        if (sum < MIN)
            MIN = sum;
        if (sum > MAX)
            MAX = sum;
    }
    uk = 0;
    for (i = 0; i < n; i++)
    {
        if (! check[i])
            b[uk++] = a[i];
    }
    if (uk <= n % k)
    {
        cout.precision(15);
        cout << fixed << (long double) MIN/q << " " << (long double) MAX/q;
        return 0;
    }
    sort(b, b + uk);
    if (uk >= q)
    {
        sum = 0;
        for (i = 0; i < q; i++)
            sum += b[i];
        if (sum < MIN)
            MIN = sum;
        sum = 0;
        for (i = uk - q; i < uk; i++)
            sum += b[i];
        if (sum > MAX)
            MAX = sum;
    }
    cout.precision(15);
    cout << fixed << (long double) MIN/q << " " << (long double) MAX/q;
    return 0;
}