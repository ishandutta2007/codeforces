#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e6 + 42;

vector<int> fact(int m) {
    vector<int> res;
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            res.push_back(i);
            while(m % i == 0) {
                m /= i;
            }
        }
    }
    if(m > 1) {
        res.push_back(m);
    }
    return res;
}

int db(int p, int q) {
    int res = 1;
    while(p % q == 0) {
        p /= q;
        res *= q;
    }
    return res;
}

void solve() {
    int p, q;
    cin >> p >> q;
    int ans = 1;
    for(auto it: fact(q)) {
        int A = db(p, it);
        int B = db(q, it);
        if(A < B) {
            ans = p;
        } else {
            ans = max(ans, p / A * B / it);
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}