#include <bits/stdc++.h>

using namespace std;

int main() {
    int freq[105] = {0};
    int n, M;
    cin >> n >> M;
    vector <int> ans(n);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        int bound = M - val;
        int bagat = 0;
        for (int j = 1; j <= 100; ++j) {
            if (freq[j] <= bound / j) {
                bound -= j * freq[j];
                bagat += freq[j];
            } else {
                bagat += bound / j;
                break;
            }
        }
        ++freq[val];
        ans[i - 1] = i - bagat - 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}