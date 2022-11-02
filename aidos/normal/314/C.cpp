#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define filename ""
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int t[maxn];
int dp[maxn];
int last[maxn];
int a[maxn];
int n;
int get(int pos) {
    int res = 0;
    while(pos >= 0) {
        res = (res + t[pos]) % mod;
        pos = (pos & (pos+1)) - 1;
    }
    return res;
}
void upd(int pos, int val) {
    while(pos < maxn) {
        t[pos] = (t[pos] + val) % mod;
        pos |= pos + 1;
    }
}

void solve() {
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = (get(x) + 1) * 1ll * x % mod;
        dp[i] = a[i];
        if(last[x] != 0) {
            dp[i] = (dp[i] - a[last[x]] + mod) % mod;
        }
        upd(x, dp[i]);
        last[x] = i;
        res = (res + dp[i]) % mod;
    }
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}