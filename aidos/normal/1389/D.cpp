#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int a[maxn];
int b[maxn];
int n, k;
int l1, r1;
int l2, r2;
void solve() {
    cin >> n >> k;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    if(r1 > r2) {
        swap(r2, r1);
        swap(l2, l1);
    }
    long long d = max(l2 - r1, 0);
    long long inter = max(r1 - max(l2, l1), 0);

    long long len = (r2 - min(l1, l2));
    long long z = inter * 1ll * n;
    if(len == 0) {
        cout << 2 * k << "\n";
        return;
    }
    if(z >= k) {
        cout << 0 << "\n";
        return;
    }

    if(d == 0) {
        if(len * n >= k) {
            cout << k - z << "\n";
            return;
        }
        cout << len*n - z + 2*(k - len * n) << "\n";
        return;
    }
    long long c = min(k/len, n*1ll);
    long long ans = (r2-r1 + l2-l1) * c;
    k -= c * len;
    if(c == n) {
        ans += k * 2ll;
    } else if(c == 0){
        ans += d + k;
    } else {
        ans += min(2ll * k, d + k);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}