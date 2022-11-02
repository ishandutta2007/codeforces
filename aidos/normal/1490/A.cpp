#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
int n;
int a[maxn];
int get(int x, int y) {
    if(x*2 >= y) return 0;
    return get(x*2, y) + 1;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans += get(min(a[i-1], a[i]), max(a[i-1], a[i]));
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}