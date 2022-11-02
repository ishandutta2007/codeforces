#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500;
const ll inf = (1ll<<50);
int n, k;
void solve() {
    cin >> n >> k;
    vector<int> ans;
    int cur = n - k;
    for(int i = 1; i <= k - cur - 1; i++) {
        ans.push_back(i);
    }
    for(int i = k; i >=k - cur; i--) {
        ans.push_back(i);
    }
    for(int x: ans) cout << x << " ";
    cout << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}