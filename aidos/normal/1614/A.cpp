#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    int l, r;
    cin >> n >>l >> r >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans =0;
    for(int i = 0; i < n; i++) {
        if(a[i] < l || a[i] > r) continue;
        if(a[i] <= k) {
            k -= a[i];
            ++ans;
        }
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