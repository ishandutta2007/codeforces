#include <bits/stdc++.h>

using namespace std;

bool is_good(vector<int> arr) {
    int n = arr.size();
    int cnt_z = 0;
    int cnt_o = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cnt_z++;
        } else if (arr[i] == 1) {
            cnt_o++;
        }
    }
    if (cnt_z * 2 > n) {
        return false;
    } 
    if (cnt_z) {
        return true;
    }
    vector<int> new_arr(n);
    for (int i = 0; i < n; i++) {
        new_arr[i] = arr[i] - 1;
    }
    return is_good(new_arr);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (is_good(arr)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}