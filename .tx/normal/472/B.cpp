#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define all(a) a.begin(),a.end()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vei a(n);
    foi(n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i += k) {
        ans += 2 * a[i] - 2;
    }
    cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}