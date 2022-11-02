#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long a[n];
    long long b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    long long x = max(a[0] * b[0], a[0] * b[m - 1]);
    long long y = max(a[n - 1] * b[0], a[n - 1] * b[m - 1]);
    if (x > y)
    {
        cout << max(y, max(a[1] * b[0], a[1] * b[m - 1]));
    }
    else
    {
        cout << max(x, max(a[n - 2] * b[0], a[n - 2] * b[m - 1]));
    }
}