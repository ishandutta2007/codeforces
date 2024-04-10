#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 100;
int n;
int a[maxn];
ll sum[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    set < ll > s;
    s.insert(0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s.count(sum[i])) {
            ans++;
            s.clear();
            s.insert(sum[i-1]);
            s.insert(sum[i]);
        }
        else s.insert(sum[i]);
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}