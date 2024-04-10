#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        arr[i] -= (n - 1 - i);
    }
    sort(arr.rbegin(), arr.rend());
    int min_ans = sum;
    for (int i = 0; i < k; i++) {
        sum -= arr[i];
        sum -= i;
        min_ans = min(min_ans, sum);
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