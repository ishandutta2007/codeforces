#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
    int n, m;
    cin >> n >> m; 
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    m = min(n, m);
    for (int i = 0; i < m; ++i) {
        vector<int> na(n);
        for (int i = 0; i < n; ++i) {
            na[i] = a[i];
            int v = 0;
            if (i) {
                v ^= a[i - 1];
            }
            if (i != n - 1) {
                v ^= a[i + 1];
            }
            na[i] |= v;
        }
        a.swap(na);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << '\n';
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