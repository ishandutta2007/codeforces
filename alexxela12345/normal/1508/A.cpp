#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int count1(string s) {
    return count(s.begin(), s.end(), '1');
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        string a, b;
        bool rev = false;
        bool b1 = count1(s1) >= n;
        bool b2 = count1(s2) >= n;
        bool b3 = count1(s3) >= n;
        if (b1) {
            if (b2) {
                a = s1;
                b = s2;
            } else if (b3) {
                a = s1;
                b = s3;
            } else {
                // !b2 & !b3
                a = s2;
                b = s3;
                rev = 1;
            }
        } else {
            if (b2) {
                if (b3) {
                    a = s2;
                    b = s3;
                } else {
                    a = s1;
                    b = s3;
                    rev = 1;
                }
            } else {
                    a = s1;
                    b = s2;
                    rev = 1;

            }
        }
        string ans;
        if (rev) {
            for (int i = 0; i < 2 * n; i++) {
                a[i] = '0' + '1' - a[i];
                b[i] = '0' + '1' - b[i];
            }
        }
        ans = "";
        int cnt = max(count1(a), count1(b));
        vector<int> arr(cnt + 1);
        int cur = 0;
        for (char c : a) {
            if (c == '1') {
                cur++;
            } else {
                arr[cur]++;
            }
        }
        cur = 0;
        for (char c : b) {
            if (c == '1') {
                cur++;
            } else {
                arr[cur]++;
            }
        }
        ans.resize(arr[0], '0');
        for (int i = 0; i < cnt; i++) {
            ans.push_back('1');
            ans.resize(ans.size() + arr[i + 1], '0');
        }
        ans.resize(3 * n, '0');
        {
            string s = a;
            int ind = 0;
            for (char c : ans) {
                if (ind != 2 * n && c == s[ind]) {
                    ind++;
                }
            }
            assert(ind == 2 * n);
        }
        {
            string s = b;
            int ind = 0;
            for (char c : ans) {
                if (ind != 2 * n && c == s[ind]) {
                    ind++;
                }
            }
            assert(ind == 2 * n);
        }
        if (rev) {
            for (int i = 0; i < 3 * n; i++) {
                ans[i] = '0' + '1' - ans[i];
            }
        }
        cout << ans << endl;
    }
}