#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }
    for(int i = 0; i < n; i++) {
        a[i] = s/(n - i);
        s -= a[i];
    }
    for(int i = 0; i < n; i++) {
        ans += -a[i] * 1ll * (n - i - 1);
        ans += a[i] * 1ll * i;
    }
    cout << ans << "\n";
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}