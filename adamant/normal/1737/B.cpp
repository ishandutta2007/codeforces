#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

int count(int n, int d) {
    // t * (t + d) <= n
    int t = sqrt(n);
    while(t * (t + d) > n) {
        t--;
    }
    return t;
}

int count(int n) {
    return count(n, 0) + count(n, 1) + count(n, 2);
}

void solve() {
    int L, R;
    cin >> L >> R;
    cout << count(R) - count(L - 1) << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    for(int n = 1; n <= 100000; n++) {
        int t = sqrt(n);
        if(n % t == 0) {
            int r = n / t;
            assert(t <= r && r <= t + 2);
            //cout << n << ' ' << t << ' ' << n / t << endl;
        }
        int b = n * (n + 1);
        //cout << n << ' ' << b << endl;
        assert(n == (int)sqrt(b));
        b = n * (n + 2);
        //cout << n << ' ' << b << endl;
        assert(n == (int)sqrt(b));
    }
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