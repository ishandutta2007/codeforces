#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    cin >> n;
    double s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    double ans = -1e18;
    double cur = 0;
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++) {
        cur += a[i];
        ans = max(ans, cur/(i + 1) + (s-cur)/(n - i - 1));
    }
    cout << setprecision(12) << fixed << ans << "\n";
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}