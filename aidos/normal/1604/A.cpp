#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    int cur = 0;
    int ans=0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cur++;
        if(cur < a[i]) {
            ans += a[i] - cur;
            cur = a[i];
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