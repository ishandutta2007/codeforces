#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;

bool IS_MULTITEST = 1;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int ans = -1;
    int sum = 0;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (ind == -1 && a[i] % x != 0) ind = i;
        if (sum % x != 0) ans = i + 1;
        else if (ind != -1) ans = max(ans, i - ind);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (IS_MULTITEST) cin >> t;
    while (t--) solve();
    return 0;
}