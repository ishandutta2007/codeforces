#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a + mod - b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    int r[n][5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> r[i][j];
        }
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b) {
        int cn = 0;
        for(int k = 0; k < 5; k++) {
            cn += r[a][k] <= r[b][k];
        }
        return cn >= 3;
    });
    for(int i = p[0]; i <= p[0]; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            int cn = 0;
            for(int k = 0; k < 5; k++) {
                cn += r[i][k] <= r[j][k];
            }
            if(cn < 3) {
                ok = false;
            }
        }
        if(ok) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}