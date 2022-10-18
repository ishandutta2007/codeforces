#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

const int maxn = 1 << 18, logn = 19;

int h[logn][maxn];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sz = 1 << n;
    for(int i = 0; i < sz; i++) {
        h[0][i] = s[i] - 'a';
    }
    for(int i = 1; i <= n; i++) {
        auto ptoh = [&](int p) {
            return make_pair(h[i - 1][p], h[i - 1][p ^ (1 << (i - 1))]);
        };
        int p[sz];
        iota(p, p + sz, 0);
        sort(p, p + sz, [&](int a, int b){return ptoh(a) < ptoh(b);});
        h[i][p[0]] = 0;
        for(int j = 1; j < sz; j++) {
            h[i][p[j]] = h[i][p[j - 1]] + (ptoh(p[j]) != ptoh(p[j - 1]));
        }
        if(i == n) {
            string ans;
            for(int j = 0; j < sz; j++) {
                ans += s[p[0] ^ j];
            }
            cout << ans << "\n";
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}