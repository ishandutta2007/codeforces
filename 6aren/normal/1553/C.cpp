#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        string a[2];
        for (int i = 0; i < s.size(); i++) {
            a[i % 2].push_back(i);
        }
        int mn = 10;
        {
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    if (s[i] == '1' || s[i] == '?') cnt[i % 2]++;
                } else {
                    if (s[i] == '1') cnt[i % 2]++; 
                }
                int mx[2];
                mx[0] = cnt[0];
                mx[1] = cnt[1];
                for (int j = i + 1; j < 10; j++) mx[j % 2]++;
                if (mx[1] < cnt[0] || mx[0] < cnt[1]) {
                    // cout << i << ' ' << mx[1] << ' ' << cnt[0] << ' ' << mx[0] << ' ' << cnt[1] << endl;
                    mn = min(mn, i + 1);
                    break;
                }
            }
        }
        {
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    if (s[i] == '1' || s[i] == '?') cnt[i % 2]++;
                } else {
                    if (s[i] == '1') cnt[i % 2]++; 
                }
                int mx[2];
                mx[0] = cnt[0];
                mx[1] = cnt[1];
                for (int j = i + 1; j < 10; j++) mx[j % 2]++;
                if (mx[1] < cnt[0] || mx[0] < cnt[1]) {
                    mn = min(mn, i + 1);
                    break;
                }
            }
        }
        cout << mn << '\n';
    }

    return 0;
}