#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6;
using ld = double;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(all(a));
    ll ans = ll(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for(int i = n; i < 2 * n - 1; i++) {
        ans = min(ans, ll(a[i] - a[i - n + 1]) * (a[2 * n - 1] - a[0]));
    }
    cout << ans;
}