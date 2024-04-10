#include <iostream>

using namespace std;
long long  a[100];
long long  b[100];
long long nul, n, i, x,ans;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0)
            a[x]++;
        if (x < 0)
            b[-x]++;
        if (x == 0)
            nul++;
    }
    for (i = 1; i <= 10; i++)
        ans += a[i] * b[i];
    ans += nul * (nul - 1) / 2;
    cout << ans;
    return 0;
}