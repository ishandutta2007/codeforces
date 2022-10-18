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
    int a[n];
    set<pair<int, int>> rem;
    int ans = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        set<pair<int, int>> nrem = {{i, 0}};
        set<int> nrems = {0};
        for(auto it: rem) {
            int g = __gcd(it.second, abs(a[i] - a[it.first]));
            if(g > 1 && !nrems.count(g)) {
                nrems.insert(g);
                nrem.emplace(it.first, g);
            }
        }
        rem = nrem;
        ans = max(ans, i - begin(rem)->first + 1);
    }
    cout << ans << "\n";
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