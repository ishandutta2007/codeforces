#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
map < int, int > cnt;
map < pair < int, int >, int > t;

main() {
    int n, x, y;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (x != y) {
            ans += (cnt[x] + cnt[y] - t[{x, y}]);
        }
        else ans += cnt[x];
        if (x == y) cnt[x]++;
        else {
            t[{x, y}]++;
            cnt[x]++;
            cnt[y]++;
        }
    }
    cout << ans << '\n';
}