#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>& r) {
    int c = 0;
    for (int x : r) {
        c += x != 2;
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(n, a) << '\n';
    }
    return 0;
}