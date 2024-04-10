#include <bits/stdc++.h>

using namespace std;

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
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int el1 = arr[i], el2 = arr[i + 1];
        if (el1 != 1 && el2 != 1) {
            cout << "Infinite" << endl;
            return 0;
        }
        if (el1 > el2) {
            swap(el1, el2);
        }
        if (el2 == 2) {
            cnt += 3;
            if (i - 1 >= 0 && arr[i - 1] == 3 && arr[i] == 1 && arr[i + 1] == 2) {
                cnt--;
            }
        } else {
            cnt += 4;
        }
    }
    cout << "Finite" << endl;
    cout << cnt << endl;
    return 0;
}