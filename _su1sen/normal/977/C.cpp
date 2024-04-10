#include<bits/stdc++.h>

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (k == 0) {
        if (a[0] == 1) {
            return -1;
        } else {
            return a[0] - 1;
        }
    } else {
        int v = a[k - 1];
        if (k == n) {
            return v;
        } else {
            return a[k] == v ? -1 : v;
        }
    }
}

int main() {
    cout << solve() << '\n';
}