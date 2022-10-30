#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, l, a;
    cin >> n >> l >> a;
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += (x - last) / a;
        last = x + y;
    }
    ans += (l - last) / a;
    cout << ans;
    return 0;
}