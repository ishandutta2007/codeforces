#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) begin(x), end(x)

#define int int64_t
const int mod = 1e9 + 7;

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

int check(vector<int> p, int k) {
    int n = p.size();
    vector<int> q(n);
    iota(all(q), 0);
    rotate(begin(p), begin(p) + k, end(p));
    vector<int> used(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            while(!used[i]) {
                used[i] = 1;
                i = p[i];
                ans++;
            }
            ans--;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        int d = (i + n - p[i]) % n;
        cnt[d]++;
    }
    int P[n];
    iota(P, P + n, 0);
    sort(P, P + n, [&](int a, int b) {
        return cnt[a] > cnt[b];
    });
    vector<int> res;
    for(int z = 0; z < 3; z++) {
        if(check(p, P[z]) <= m) {
            res.push_back(P[z]);
        }
    }
    sort(all(res));
    cout << res.size() << ' ';
    for(auto it: res) {
        cout << it << ' ';
    }
    cout << "\n";
    
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