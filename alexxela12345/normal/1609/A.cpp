#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_ans = 0;
    for (int i = 0; i < n; i++) {
        auto arr2 = arr;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                while (arr[j] % 2 == 0) {
                    arr[j] /= 2;
                    arr[i] *= 2;
                }
            }
        }
        max_ans = max(max_ans, accumulate(arr.begin(), arr.end(), 0LL));
        arr = arr2;
    }
    cout << max_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}