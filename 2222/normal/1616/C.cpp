#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>

using namespace std;

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
        int res = max(n - 2, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int m = 0;
                const int d = j - i;
                const int w = a[j] - a[i];
                const int b = a[i] * d - w * i;
                for (int k = 0; k < n; ++k) {
                    m += (a[k] * d != b + w * k);
                }
                res = min(res, m);
            }
        }
        cout << res << endl;
    }
    return 0;
}