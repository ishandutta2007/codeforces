#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> pos, neg, zero;
        int psum = 0, nsum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                pos.push_back(arr[i]);
                psum += arr[i];
            } else if (arr[i] < 0) {
                neg.push_back(arr[i]);
                nsum -= arr[i];
            } else {
                zero.push_back(0);
            }
        }
        if (psum == nsum) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (psum > nsum) {
                for (int el : pos) {
                    cout << el << " ";
                }
                for (int el : zero) {
                    cout << el << " ";
                }
                for (int el : neg) {
                    cout << el << " ";
                }
            } else {
                for (int el : neg) {
                    cout << el << " ";
                }
                for (int el : zero) {
                    cout << el << " ";
                }
                for (int el : pos) {
                    cout << el << " ";
                }
            }
            cout << endl;
        }
    }
}