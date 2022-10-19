#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int x[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    x[n] = a[n];
    for (int i = n - 1; i >= 1; --i)
    {
        x[i] = min(a[i], x[i + 1] - 1);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        if (x[i] > 0)
            ans += x[i];
    cout << ans << endl;
    return 0;
}