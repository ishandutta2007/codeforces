#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
    int n; 
    cin >> n;
    vector<int> a(n);
    cout << 3 * n << '\n';
    auto ask = [&](int t, int i, int j) {
        cout << t << " " << i + 1 << " " << j + 1 << '\n';
    };
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; ++i) {
        ask(1, 2 * i, 2 * i + 1);
        ask(2, 2 * i, 2 * i + 1);
        ask(1, 2 * i, 2 * i + 1);
        ask(1, 2 * i, 2 * i + 1);
        ask(2, 2 * i, 2 * i + 1);
        ask(1, 2 * i, 2 * i + 1);
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; 
    cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve_case(tc);
    }
    return 0;
}

/**
 * a[j]
 * -a[i]
 */