#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

const int maxn = 1e6 + 42;

int F[maxn], RF[maxn];

int fact(int n) {
    return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % mod : 1;
}
int rfact(int n) {
    return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}

int nCr(int n, int r) {
    return fact(n) * rfact(r) % mod * rfact(n - r) % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> pr;
    auto add = [&](int a, int b) {
        pr.insert({min(a, b), max(a, b)});
    };
    auto opp = [&](int x) {
        return (n - 1) ^ x;
    };
    if(k == 0) {
        for(int i = 0; i < n / 2; i++) {
            cout << i << ' ' << opp(i) << "\n";
        }
    } else if(k + 1 < n) {
        add(n - 1, k);
        add(0, opp(k));
        for(int i = 1; i < n - 1; i++) {
            if(i != k && i != opp(k)) {
                add(i, opp(i));
            }
        }
        for(auto it: pr) {
            cout << it.first << ' ' << it.second << "\n";
        }
    } else {
        if(n == 4) {
            cout << -1 << "\n";
        } else {
            add(n - 1, n - 2);
            add(n - 3, 1);
            add(0, 2);
            for(int i = 3; i < n - 3; i++) {
                add(i, opp(i));
            }            
            int ns = 0;
            for(auto it: pr) {
                cout << it.first << ' ' << it.second << "\n";
                ns += it.first & it.second;
            }
        }
    }
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