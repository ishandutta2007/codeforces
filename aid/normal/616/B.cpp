#include <iostream>

using namespace std;

const int INF = 1000 * 1000 * 1000 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = INF;
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            cur = min(cur, x);
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}