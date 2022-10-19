#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

long long n, m, k;
long long a[N];

long long max1, max2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2)
            max2 = a[i];
    }
    long long sum = (k * max1 + max2);
    long long ans = (m / (k + 1)) * sum;
    ans += ((m % (k + 1)) * max1);
    cout << ans << endl;
    return 0;
}