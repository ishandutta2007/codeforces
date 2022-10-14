#include <bits/stdc++.h>

using namespace std;

struct star {
    int x, y, l;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <star> ans;
    vector <vector<bool>> used(n, vector <bool> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                int len = 0;
                for (int l = 1; i + l < n && i - l >= 0 && j + l < m && j - l >= 0 && a[i + l][j] == '*' && a[i - l][j] == '*' && a[i][j - l] == '*' && a[i][j + l] == '*'; l++) {
                    len = l;
                    used[i + l][j] = true;
                    used[i - l][j] = true;
                    used[i][j - l] = true;
                    used[i][j + l] = true;
                }
                if (len == 0) {
                    continue;
                }
                used[i][j] = true;
                star now;
                now.l = len;
                now.x = i + 1;
                now.y = j + 1;
                ans.push_back(now);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' && used[i][j] == false) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto c : ans) {
        cout << c.x << " " << c.y << " " << c.l << "\n";
    }
    return 0;
}