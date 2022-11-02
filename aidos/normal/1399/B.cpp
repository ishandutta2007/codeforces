#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)100200;
const ll inf = (1ll<<50);

int n;
int a[maxn], b[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cura = *min_element(a, a + n), curb = *min_element(b, b + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int sa = a[i] - cura;
        int sb = b[i] - curb;
        ans += max(sa, sb);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}