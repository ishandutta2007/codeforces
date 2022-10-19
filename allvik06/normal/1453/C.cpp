#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector <vector <char>> tmp;

vector <int> make_ans(int n, vector <vector <char>>& a) {
    vector <int> minn(10, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minn[a[i][j] - '0'] = i;
        }
    }
    vector <int> ans(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < n; ++j) {
            int left = n;
            int right = -1;
            for (int k = 0; k < n; ++k) {
                if (a[j][k] - '0' == i) {
                    left = min(left, k);
                    right = max(right, k);
                }
            }
            if (left == n) continue;
            ans[i] = max(ans[i], (n - left - 1) * (minn[i] - j));
            ans[i] = max(ans[i], right * (minn[i] - j));
            ans[i] = max(ans[i], (right - left) * (n - j - 1));
        }
    }
    return ans;
}

void rev(int n, vector <vector <char>>& a) {
    tmp.assign(n, vector <char> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[j][n - i - 1] = a[i][j];
        }
    }
    a.swap(tmp);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <char>> a(n, vector <char> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> a[i][j];
        }
        vector <int> ans = make_ans(n, a);
        for (int i = 0; i < 4; ++i) {
            vector <int> cha = make_ans(n, a);
            for (int j = 0; j < 10; ++j) ans[j] = max(ans[j], cha[j]);
            rev(n, a);
        }
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}