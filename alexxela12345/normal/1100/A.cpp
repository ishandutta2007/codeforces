#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int tot_sum = 0;
    for (int i = 0; i < n; i++) {
        tot_sum += arr[i];
    }
    int max_mod_s = 0;
    for (int i = 0; i < k; i++) {
        int cur_sum = tot_sum;
        for (int j = i; j < n; j += k) {
            cur_sum -= arr[j];
        }
        if (abs(cur_sum) > abs(max_mod_s)) {
            max_mod_s = abs(cur_sum);
        }
    }
    cout << max_mod_s << endl;
    return 0;
}