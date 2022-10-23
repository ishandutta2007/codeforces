#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> v(k);
    v[0] = {'a'};
    for (int i = 1; i < k; ++i) {
        v[i] = v[i - 1];
        for (int j = i - 1; j >= 1; j--) {
            v[i].push_back((char) ('a' + i));
            v[i].push_back((char) ('a' + j));
        }
        v[i].push_back((char) ('a' + i));
        v[i].push_back((char) ('a' + i));
        v[i].push_back('a');

        if (v[i].size() >= n) {
            for (int t = 0; t < n; ++t) {
                cout << v[i][t];
            }
            cout << '\n';
            return 0;
        }
    }
    vector<char> ans = v[k - 1];
    while (ans.size() < n) {
        for (char c : v[k - 1]) {
            ans.push_back(c);
        }
    }
    for (int t = 0; t < n; ++t) {
        cout << ans[t];
    }
    cout << '\n';
    return 0;
}