#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n + 1);
    int mn = 0, mx = 0;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    int l = -mn, r = w - mx;
    cout << max(0, r - l + 1) << '\n';
    return 0;
}