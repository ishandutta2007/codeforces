#include <iostream>
#include <cmath>

using namespace std;

const int MAXM = 100 * 1000 + 5;
int d[MAXM], h[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> d[i] >> h[i];
        d[i]--;
    }
    int ans = h[0] + d[0];
    for(int i = 0; i + 1 < m; i++) {
        int dd = d[i + 1] - d[i], dh = h[i + 1] - h[i];
        if(dd < (int)abs(dh)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = max(ans, h[i] + (dd + dh) / 2);
    }
    ans = max(ans, h[m - 1] + (n - 1 - d[m - 1]));
    cout << ans << '\n';
    return 0;
}