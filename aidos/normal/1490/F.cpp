#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
int n;
int a[maxn];
int cnt[maxn];
void solve() {
    cin >> n;
    map<int, int> c;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        c[x]++;
        cnt[i] = 0;
    }
    for(auto e: c) {
        cnt[e.second]++;
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        ans = max(cnt[i] * i, ans);
        cnt[i-1] += cnt[i];
    }
    cout << n - ans << "\n";
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