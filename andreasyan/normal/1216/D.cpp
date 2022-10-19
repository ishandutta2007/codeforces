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
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int z = a[2] - a[1];
    for (int i = 2; i <= n; ++i)
        z = gcd(z, a[i] - a[i - 1]);
    int x = a[1];
    for (int i = 1; i <= n; ++i)
        x = max(x, a[i]);
    long long y = 0;
    for (int i = 1; i <= n; ++i)
    {
        y += (x - a[i]) / z;
    }
    cout << y << ' ' << z << endl;
    return 0;
}