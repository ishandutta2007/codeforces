#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int a[maxn];
int n;
int get(int l, int r) {
    if(l>r) return 0;
    int mn = min_element(a + l, a + r + 1) - a;
    int ans = r - l + 1;
    for(int i = l; i <= r; i++) {
        if(i != mn) {
            a[i] -= a[mn];
        }
    }
    return min(r-l+1, get(l, mn - 1) + get(mn+1, r) + a[mn]);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << get(0, n - 1) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}