#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector <int> x(k);
    for (auto &c : x) {
        cin >> c;
    }
    vector <vector<int>> gist(n + 1);
    for (int i = 0; i < k; i++) {
        gist[x[i]].push_back(i);
    }
    set <int> s;
    for (auto &c : x) {
        s.insert(c);
    }
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            ans++;
        }
    }
    if (n == 1 && k > 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (gist[i].size() == 0 || gist[i + 1].size() == 0 || gist[i][0] > gist[i + 1].back()) {
                ans++;
            }
            continue;
        }
        if (i == n) {
            if (gist[i].size() == 0 || gist[i - 1].size() == 0 || gist[i][0] > gist[i - 1].back()) {
                ans++;
            }
            continue;
        }
        if (gist[i].size() == 0 || gist[i - 1].size() == 0 || gist[i][0] > gist[i - 1].back()) {
            ans++;
        }
        if (gist[i].size() == 0 || gist[i + 1].size() == 0 || gist[i][0] > gist[i + 1].back()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}