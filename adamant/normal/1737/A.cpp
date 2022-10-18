#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto c: s) {
        cnt[c]++;
    }
    string ans = "";
    for(int i = 0; i < k; i++) {
        int need = n / k;
        char c;
        for(c = 'a'; c <= 'z'; c++) {
            if(cnt[c] && need) {
                cnt[c]--;
                need--;
            } else {
                break;
            }
        }
        ans += c;
        for(; c <= 'z'; c++) {
            if(cnt[c]) {
                int t = min(need, cnt[c]);
                cnt[c] -= t;
                need -= t;
            }
        }
        while(need) {
            int mx = 0;
            for(auto &[c, cn]: cnt) {
                mx = max(mx, cn);
            }
            for(auto &[c, cn]: cnt) {
                if(cn == mx) {
                    int t = min((int)1, need);
                    need -= t;
                    cnt[c] -= t;
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
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