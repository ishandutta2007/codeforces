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
        int k;
        cin >> k;
        string s;
        cin >> s;
        vector<pair<int, int>> arr;
        int lastw = -1e9;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (lastw != i - 1 && lastw != -1e9) {
                    arr.push_back({i - lastw - 1, i - 1});
                }
                lastw = i;
            }
        }
        sort(arr.begin(), arr.end());
        for (auto &el : arr) {
            int cnt = el.first;
            int pos = el.second;
            while (k > 0 && cnt > 0) {
                s[pos] = 'W';
                pos--;
                cnt--;
                k--;
            }
        }
        int firstw = 0;
        while (firstw < n && s[firstw] == 'L') {
            firstw++;
        }
        while (firstw > 0 && k > 0) {
            firstw--;
            s[firstw] = 'W';
            k--;
        }
        lastw = n - 1;
        while (lastw >= 0 && s[lastw] == 'L') {
            lastw--;
        }
        while (lastw + 1 < n && k > 0) {
            lastw++;
            s[lastw] = 'W';
            k--;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (i != 0 && s[i - 1] == 'W') {
                    ans++;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
}