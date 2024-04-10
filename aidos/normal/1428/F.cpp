#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
string s;
vector<int> g[maxn];
ll dp[maxn];
int a[maxn];
int t[20][maxn];
int lg[maxn];
void build() {
    for(int i = 1; i <= n; i++) {
        t[0][i] = a[i];
    }
    for(int i = 2; i <= n; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for(int k = 1; (1<<k) <= n; k++) {
        for(int i = 1; i + (1<<k) - 1 <= n; i++) {
            t[k][i] = max(t[k-1][i], t[k-1][i + (1<<(k-1))]);
        }
    }
}
int getmax(int l, int r) {
    int k = lg[r-l+1];
    return max(t[k][l], t[k][r-(1<<k) + 1]);
}
void solve(){
    cin >> n >> s;
    s = "#"+s;
    for(int i = n; i >= 1; i--) {
        if(s[i] == '0') a[i] = 0;
        else a[i] = a[i+1] + 1;
    }
    build();
    int last = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        if(s[i] == '0') {
            last = i;
            continue;
        }
        int l = 1, r = last;
        int res = 1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(getmax(mid, last) < i - last) {
                res = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
      //  cout << res << " ";
        dp[i] += i - res + 1;
    }
    //cout << "\n";
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
       // cout << dp[i] << " ";
        ans += dp[i];
    }
    cout << ans << "\n";
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}