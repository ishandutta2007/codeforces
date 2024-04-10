#include<bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    if (k > (n - 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    vector<int> a(n);
    int v = 0;
    for (int i = 0; i < n; i += 2) {
        a[i] = ++v;
    }
    for (int i = 1; i < n; i += 2) {
        a[i] = ++v;
    }
    sort(a.begin() + 2 * k, a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}