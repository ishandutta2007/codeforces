#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

#define int int64_t
const int mod = 998244353;

const int maxn = 1e5 + 42;
int a[maxn];
int ans[maxn][2][201];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(ans, 0, sizeof(ans));
    if(a[0] == -1) {
        fill(ans[0][0] + 1, ans[0][0] + 201, 1);
    } else {
        ans[0][0][a[0]] = 1;
    }
    for(int i = 1; i < n; i++) {
        if(a[i] != -1) {
            for(int z = 0; z <= 1; z++) {
                for(int pr = 1; pr <= 200; pr++) {
                    if(i == n - 1 && a[i] > pr) {
                        continue;
                    } else if(a[i] >= pr) {
                        ans[i][a[i] == pr][a[i]] += ans[i - 1][z][pr];
                        ans[i][a[i] == pr][a[i]] %= mod;
                    } else if(z) {
                        ans[i][1][a[i]] += ans[i - 1][z][pr];
                        ans[i][1][a[i]] %= mod;
                    }
                }
            }
        } else {
            for(int pr = 1; pr <= 200; pr++) {
                ans[i][1][0] += ans[i - 1][1][pr];
                ans[i][1][0] %= mod;
            }
            for(int nw = 1; nw <= 200; nw++) {
                ans[i][1][nw] = (ans[i][1][nw - 1] + ans[i - 1][0][nw]
                + 2 * mod - ans[i - 1][0][nw - 1] - ans[i - 1][1][nw - 1]) % mod;
                if(i != n - 1) {
                    ans[i][0][nw] = (ans[i][0][nw - 1] + ans[i - 1][0][nw - 1] + ans[i - 1][1][nw - 1]) % mod;
                    
                }
            }
            ans[i][1][0] = 0;
        }
    }
    int res = 0;
    for(int i = 1; i <= 200; i++) {
        res += ans[n - 1][0][i] + ans[n - 1][1][i];
        res %= mod;
    }
    cout << res << endl;
    return 0;
}