#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void solve() {
    int n;
    cin >> n;
    int total = 0;
    vector<int> Ans(n), psum(n);
    for(int i = n - 1; i >= 0; i--) {
        // need at least i / 2 Rs before us to consume everything
        int ans = bpow(2, mod - 1 -  i / 2);
        if(i + 1 < n) {
            ans = ans * bpow(2, mod - 2) % mod;
        }
        
        if(2 * i + 1 < n) {
            ans = ans * (mod + 1 - psum[2 * i + 1]) % mod;
        }
        
        Ans[i] = ans;
        psum[i] = Ans[i];
        if(i + 1 < n) {
            psum[i] = (psum[i] + psum[i + 1]) % mod;
        }
    }
    for(auto it: Ans) {
        total += it;
        cout << it << ' ';
    }
    cout << "\n";
    //cout << "! " << total % mod << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //t = 10000;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}