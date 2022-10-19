#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    long long ans = 0;
    for (int i = 0, j = n - 1; i < n / 2; ++i, --j)
        ans += ((a[i] + a[j]) * (a[i] + a[j]));

    cout << ans << endl;

    return 0;
}