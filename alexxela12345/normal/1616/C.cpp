#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

const ldb EPS = 1e-6;

void solve() {
    int n;
    cin >> n;
    vector<ldb> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int min_ans = n - 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            ldb k = (arr[j] - arr[i]) / (j - i);
            ldb b = arr[i] - k * i;
            int cur_cnt = 0;
            for (int i = 0; i < n; i++) {
                if (fabsl(arr[i] - k * i - b) > EPS) {
                    cur_cnt++;
                }
            }
            min_ans = min(min_ans, cur_cnt);
        }
    }
    cout << min_ans << endl;
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