#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans2 = arr[n - 1] + m;
    while (m) {
        arr[0]++;
        int i = 0;
        while (i < n - 1 && arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            i++;
        }
        m--;
    }
    cout << arr[n - 1] << " " << ans2 << endl;
    return 0;
}