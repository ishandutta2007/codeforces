#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
pair<int, int> a[maxn];
void solve() {
    cin >> n;
    int ans = 0;
    for(int c = 1; c <= 9; c++) {
        ll cur = c;
        while(cur <= n) {
            ans++;
            cur = cur * 10 + c;
        }
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}