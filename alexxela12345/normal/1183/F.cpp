#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> good(n, -1);
        for (int i = 1; i < n; i++) {
            int cur = i - 1;
            while (cur != -1 && arr[i] % arr[cur] == 0) {
                cur = good[cur];
            }
            good[i] = cur;
        }
        int max_ans = -1;
        for (int i = 0; i < n; i++) {
            max_ans = max(max_ans, arr[i]);
            if (good[i] != -1) {
                max_ans = max(max_ans, arr[i] + arr[good[i]]);
                int cur = good[good[i]];
                while (cur != -1 && (arr[i] % arr[cur] == 0 || arr[good[i]] % arr[cur] == 0)) {
                    cur = good[cur];
                }
                if (cur != -1) {
                    max_ans = max(max_ans, arr[i] + arr[good[i]] + arr[cur]);
                }
            }
        }
        cout << max_ans << endl;
    }
}