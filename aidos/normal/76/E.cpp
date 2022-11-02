
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
int n, m, k;
ll calc(vector<int> a) {
    sort(a.begin(), a.end());
    ll ans=0;
    ll sum = 0;
    for(ll i = 0; i < a.size(); i++) {
        ans += a[i] * 1ll * a[i] * (n-1);
        ans -= 2 * a[i] * sum;
        sum += a[i];
    }
    return ans;
}
void solve() {
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    cout << calc(a) + calc(b) << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}