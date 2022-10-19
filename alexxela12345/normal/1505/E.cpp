#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> arr(h);
    for (int i = 0; i < h; i++) {
        cin >> arr[i];
    }
    int i = 0;
    int j = 0;
    int ans = 0;
    if (arr[i][j] == '*')
        ans++;
    arr[i][j] = '.';
    vector<vector<int>> used(h, vector<int> (w));
    while (i != h - 1 || j != w - 1) {
        deque<pair<int, int>> q;
        q.push_back({i, j});
        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second; 
            q.pop_front();
            if (arr[a][b] == '*') {
                i = a;
                j = b;
                break;
            }
            if (b + 1 < w && !used[a][b + 1]) {
                q.push_back({a, b + 1});
                used[a][b + 1] = 1;
            }
            if (a + 1 < h && !used[a + 1][b]) {
                q.push_back({a + 1, b});
                used[a + 1][b] = 1;
            }
        }
        if (arr[i][j] == '*') {
            ans++;
            arr[i][j] = '.';
        } else {
            break;
        }
    }

    cout << ans << endl;
}