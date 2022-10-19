#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
long long k;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = n / 2 + 2; i <= n; ++i)
    {
        long long t = a[i] - a[i - 1];
        long long q = i - (n / 2 + 1);
        if (q * t <= k)
        {
            k -= q * t;
        }
        else
        {
            cout << a[i - 1] + (k / q) << endl;
            return 0;
        }
    }
    long long q = n - (n / 2 + 1) + 1;
    cout << a[n] + (k / q) << endl;
    return 0;
}