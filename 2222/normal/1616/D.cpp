#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>

using namespace std;

int solve(const int a[], int n) {
    if (n < 2) return 0;
    int64_t x = a[0];
    for (int i = 1; i < n; ++i) {
        if (x + a[i] < 0) {
            return 1 + solve(a + (i + 1), n - (i + 1));
        }
        x = min(x + a[i], (int64_t)a[i]);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    for (cin >> tc; tc --> 0; ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int x;
        cin >> x;
        for (int &y : a) {
            y -= x;
        }
        cout << n - solve(a.data(), n) << endl;
    }
    return 0;
}