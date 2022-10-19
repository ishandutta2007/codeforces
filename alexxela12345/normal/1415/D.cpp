//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int min_ans = 2 * n;
    if (n < 50) {
        for (int i = 0; i < n; i++) {
            int cur_x = 0;
            for (int j = i + 1; j <= n; j++) {
                cur_x ^= arr[j - 1];
                for (int k = j; k < n; k++) {
                    int cur_y = 0;
                    for (int l = k + 1; l <= n; l++) {
                        cur_y ^= arr[l - 1];
                        if (cur_x > cur_y) {
                            min_ans = min(min_ans, j - i + l - k - 2);
                        }
                    }
                }
            }
        }
        if (min_ans == 2 * n)
            min_ans = -1;
        cout << min_ans << endl;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (i + 2 < n) {
            if (arr[i] > (arr[i + 1] ^ arr[i + 2])) {
                min_ans = min(min_ans, 1);
            } else if ((arr[i] ^ arr[i + 1]) > arr[i + 2]) {
                min_ans = min(min_ans, 1);
            }
        }
        if (i + 3 < n) {
            if ((arr[i] ^ arr[i + 1] ^ arr[i + 2]) > arr[i + 3]) {
                min_ans = min(min_ans, 2);
            }
            if ((arr[i] ^ arr[i + 1]) > (arr[i + 3] ^ arr[i + 2])) {
                min_ans = min(min_ans, 2);
            }
            if ((arr[i]) > (arr[i + 3] ^ arr[i + 2] ^ arr[i + 1])) {
                min_ans = min(min_ans, 2);
            }
        }
    }
    if (min_ans == 2 * n)
        min_ans = -1;
    cout << min_ans << endl;
}