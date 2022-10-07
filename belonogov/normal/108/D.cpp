#include <iostream>
#include <cstdio>

using namespace std;
int a[100000];

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int i, n, m, h, sum = 0;
    long double res = 1, d, d1;
    cin >> n >> m >> h;
    h--;
    n--;
    for (i = 0; i < m; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum -=a[h];
    a[h]--;
    if (sum + a[h] < n)
    {
        cout << -1;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        d1 = (sum - i);
        d = d1 / ((sum - i) + a[h]);
        res = res * d;
    }
    cout.precision(15);
    cout << fixed << 1 - res;
    return 0;
}