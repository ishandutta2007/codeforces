#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

int half(int x, int y) {
    return 2 * (x > 0) + (y > 0);
}

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a - b != 1) {
            cout << "NO" << endl;
        } else {
            cout << (is_prime(a + b) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}