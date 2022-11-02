#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = k/(a[n-2] + a[n-1]);
    ans *= 2;
    k %= (a[n - 2] + a[n-1]);
    if(k >0) {
        k -= a[n-1];
        ans++;
    }
    if(k > 0) {
        k -= a[n-2];
        ans++;
    }
    cout << ans << "\n";
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