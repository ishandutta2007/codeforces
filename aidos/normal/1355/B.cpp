#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    ll s=0;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cnt[i] += cnt[i-1];
        ans += cnt[i]/i;
        cnt[i] %= i;
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