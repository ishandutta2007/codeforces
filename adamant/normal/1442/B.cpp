#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;

int bpow(int x, int n) {
    return n > 0 ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], b[k];
    set<int> h = {-1, n}, g;
    int rv[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        rv[a[i]] = i;
        h.insert(i);
    }
    for(int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
        g.insert(b[i]);
    }
    int ans = 1;
    for(int i = 0; i < k; i++) {
        auto it = h.find(rv[b[i]]);
        auto L = prev(it);
        auto R = next(it);
        int oka = (*L >= 0 && !g.count(a[*L]));
        int okb = (*R < n && !g.count(a[*R]));
        int ok = oka + okb;
        ans = ans * ok % mod;
        if(oka) {
            h.erase(L);
        } else if(okb) {
            h.erase(R);
        }
        g.erase(b[i]);
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