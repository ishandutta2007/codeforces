#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    int cnt_diff = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        if (cnt[x] == 0) {
            cnt_diff++;
        }
        cnt[x]++;
        if (cnt_diff == n) {
            cout << 1;
            cnt_diff = 0;
            for (int i = 0; i < n; i++) {
                cnt[i]--;
                if (cnt[i] > 0) {
                    cnt_diff++;
                }
            }
        } else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}