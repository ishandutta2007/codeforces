#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int w, k, h;
    cin >> w >> h >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += 2 * ((w - 1) + (h - 1));
        w -= 4;
        h -= 4;
    }
    cout << ans;
    return 0;
}