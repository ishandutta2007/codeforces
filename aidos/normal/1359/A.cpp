#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m, k;
void solve() {
    cin >> n >> m >> k;
    int ans = 0;
    for(int x = 0; x <= n/k && x <= m; x++) {
        for(int y = 0; y <= x && x + y <= m; y++) {
            if((k-2) * y >= m - x - y) ans = max(ans, x-y);
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}