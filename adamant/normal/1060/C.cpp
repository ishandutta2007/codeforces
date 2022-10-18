#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxs = 2e3 * 2e3 + 42;
int lens[maxs];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int x;
    cin >> x;
    for(int i = 0; i < n; i++) {
        int sm = 0;
        for(int j = 0; i + j < n; j++) {
            sm += a[i + j];
            lens[sm] = max(lens[sm], j + 1);
        }
    }
    for(int i = 1; i < maxs; i++) {
        lens[i] = max(lens[i], lens[i - 1]);
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int sm = 0;
        for(int j = 0; i + j < m; j++) {
            sm += b[i + j];
            ans = max(ans, (j + 1) * lens[min(maxs - 1, x / sm)]);
        }
    }
    cout << ans << endl;
}