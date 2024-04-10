#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

long double n;
long double k, m;
long double a[N];

long double s[N];
int main()
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(11);
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + (int)n);
    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = (s[i + 1] + a[i]);
    }
    long double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > m)
            break;
        ans = max(ans, (s[i] + min(m - i, (n - i) * k))  / (n - i));
    }
    cout << ans << endl;
    return 0;
}