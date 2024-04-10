#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
int n, m;
string s[10];
int sum[4][maxn];
int can[32][32];
void solve() {
    cin >> n >> m;
    if(n >= 4) {
        cout << -1 << "\n";
        return;
    }
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        cin>>s[i];
    }
    vector<int> dp(1<<n);
    for(int j = 0; j < (1<<n); j++) {
        for(int k = 0; k < (1<<n); k++) {
            int mask = j^k;
            int good = 1;
            for(int i = 1; i < n; i++) {
                if(mask & (1<<i)) {
                    if(mask&(1<<(i-1))) {
                        good=0;
                    }
                } else {
                    if(mask&(1<<(i-1))) {

                    } else {
                        good = 0;
                    }
                }
            }
            can[j][k] = good;
        }
    }
    for(int i = 0; i < m; i++) {
        vector<int> ndp(1<<n, 1e9);
        int cur = 0;
        for(int j = 0; j < n; j++) {
            cur |= (s[j][i] - '0') << j;
        }
        for(int j = 0; j < (1<<n); j++) {
            int t = __builtin_popcount(j^cur);
            for(int k = 0; k < (1<<n); k++) {
                if(can[j][k])ndp[j] = min(dp[k] +  t, ndp[j]);
            }
        }
        dp.swap(ndp);
    }
    cout << *min_element(dp.begin(), dp.end()) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}