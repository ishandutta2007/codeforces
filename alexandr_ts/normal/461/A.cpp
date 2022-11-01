#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
int a[1000000];
int main()
{
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    ll ans = 0;
    ans += s;
    sort(a, a + n);
    for (int i = 0; i <= n - 2; i++)
    {
        ans += s;
        s -= a[i];
    }
    cout << ans;
    return 0;
}