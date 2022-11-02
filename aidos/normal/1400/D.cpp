#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
int n, m;
int a[maxn];
void solve() {
    cin >> n;
    vector < int > cnt(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                ans += cur;
            }
            cur += cnt[j];
        }
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) cnt[j]++;
        }
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