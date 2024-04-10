#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];

main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int cur = n - 1;
    ll ans = 0;
    while (cur >= 0)
    {
        ans += 2 * a[cur] - 2;
        cur -= k;
    }
    cout << ans;
}