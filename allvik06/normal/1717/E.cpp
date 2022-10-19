#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

inline void solve() {
    int n;
    cin >> n;
    vector <vector <int>> all(n + 1);
    vector <int> phi(n + 1), mind(n + 1), pw(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (mind[i] == 0) {
            mind[i] = i;
            pw[i] = i;
            phi[i] = i - 1;
        } else {
            if (pw[i] == i) {
                phi[i] = pw[i] - pw[i] / mind[i];
            } else {
                phi[i] = phi[pw[i]] * phi[i / pw[i]];
            }
        }
        for (int j = i; j <= n; j += i) {
            all[j].push_back(i);
            if (mind[j] == 0 && i > 1) {
                mind[j] = i;
                pw[j] = i;
                if (mind[j / i] == i) pw[j] *= pw[j / i];
            }
        }
    }
    int ans = 0;
    for (int c = 1; c <= n; ++c) {
        int x = n - c;
        for (int g : all[x]) {
            int cnt = phi[x / g];
            ans += c / gcd(c, g) * g * cnt;
            ans %= mod;
        }
    }
    cout << ans;
}

inline void solve2() {
    int n;
    cin >> n;
    int ans = 0;
    for (int c = 1; c < n; ++c) {
        int sum = 0;
        for (int b = 1; b < n - c; ++b) {
            int a = n - b - c;
            int g = gcd(a, b);
            sum += c * g / gcd(c, g);
        }
        cout << sum << "\n";
    }
    cout << ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
 9
8
12
8
5
0
0

1 5 -> 1
2 4 -> 2
3 3 -> 3
4 2 -> 2
5 1 -> 1
 */