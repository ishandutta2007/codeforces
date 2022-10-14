#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> e;
    int m = n;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        j %= n;
        e.pb(i, j);
    }
    int cur = 0;
    while (!is_prime(m)) {
        e.pb(cur, cur + n / 2);
        cur++;
        m++;
    }
    cout << m << "\n";
    for (auto &c : e) {
        cout << c.fi + 1 << " " << c.se + 1 << "\n";
    }
    return 0;
}