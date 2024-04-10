#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(5);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 5; j++) {
            int k = 0;
            if (arr[i] == (j - 1) % 2 + 1) {
                k = 1;
            }
            dp[j] = max(dp[j - 1], dp[j] + k);
        }
    }
    cout << dp[4] << endl;
}