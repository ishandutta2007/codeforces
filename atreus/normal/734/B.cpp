#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int y = min (k5, k6);
    long long ans = 256 * min(k2, y);
    k2 -= min(k2, y);
    ans += 32 * min(k2, k3);
    cout << ans << endl;
}