#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
ll dp[2][111][111][111];
int n, a[111];
string s;
ll get(int c, int l, int r, int cnt) {
    if(cnt < 0) return -(1ll<<60);
    if(l > r) {
        if(cnt > 0) return -(1ll<<60);
        return 0;
    }
    ll &res = dp[c][l][r][cnt];
    if(res != -1) return res;
    res = -(1ll<<60);
    if(cnt == 0) {
        for(int cc = 1; cc <= r - l + 1; cc++) {
            res = max(res, get(0, l, r, cc) + a[cc]);
            res = max(res, get(1, l, r, cc) + a[cc]);
        }
    } else {
        for(int m = l; m <= r; m++) {
            if(s[m] - '0' == c) {
                res = max(res, get(0, l, m - 1, 0) + get(c, m + 1, r, cnt - 1));
            }
        }
    }
    return res;
}
void solve() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << get(0, 0, n-1, 0)<< "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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