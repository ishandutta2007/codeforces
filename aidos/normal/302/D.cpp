#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, d;
int a[maxn];
int x[maxn], y[maxn];
int dp[maxn];
int ok(int c) {
    for(int i = 1; i <= n; i++) dp[i] = -1;
    dp[1] = c;
    for(int it = 1; it <= n; it++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) > dp[i]) continue;
                dp[j] = max(dp[j], dp[i] - d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) + a[j]);
            }
        }
    }
    return dp[n] >= 0;
}
void solve() {
    cin >> n >> d;
    for(int i = 2; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int l = 0, r = 4e7, res = -1;

    while(l <= r) {
        int mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            r = mid-1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}