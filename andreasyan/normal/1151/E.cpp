#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
long long a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    long long ans = 0;

    ans += (a[1]) * (n - a[1] + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i - 1] <= a[i])
            ans += (a[i] - a[i - 1]) * (n - a[i] + 1);
        else
            ans += (a[i]) * (a[i - 1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}