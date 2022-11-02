#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
long long ans = 0;
int n;
vector<int> g[maxn];
long long a[maxn];
long long sum[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n+i] = a[i];
    }
    for(int i = 2; i <= 2*n; i++) {
        sum[i] = sum[i-2] + a[i];
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        ans = max(ans, sum[i] - sum[i-n-1]);
    }
    cout << ans << "\n";
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