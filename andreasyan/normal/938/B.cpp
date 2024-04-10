#include <bits/stdc++.h>
using namespace std;
const int N = 100005, m = 1000000;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = m;
    for (int i = 0; i < n - 1; ++i)
    {
        ans = min(ans, max(a[i] - 1, m - a[i + 1]));
    }
    ans = min(ans, a[n - 1] - 1);
    ans = min(ans, m - a[0]);
    cout << ans << endl;
    return 0;
}