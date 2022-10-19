#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    bool table[n][m];
    for (int i = 0; i < n; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < m; j++) {
        table[i][j] = row[j] == '1';
      }
    }
    int ans = 0;
    for (int P = 0; P < 2; P++) {
      vector<int> robots;
      int discard = 0;
      for (int i = P&1; i < m+n; i+=2) {
        int k = robots.size();
        vector<int> newrobots;
        vector<int> positions;
        for (int j = min(i, m-1); j >= max(0, i-n+1); j--) {
          if (table[i-j][j]) {
            positions.push_back(i-j);
          }
        }
        int m = positions.size();
        int l = 0;
        int firstrobot = (k ? robots[0] : n+m);
        while (l < m && positions[l] < firstrobot) {
          l++;
        }
        if (l) {
          newrobots.push_back(positions[l-1]+1);
        }
        for (int i = 0; i < k; i++) {
          int next = (i == k-1 ? n+m : robots[i+1]);
          while (l < m && positions[l] < next) l++;
          int newrobotpos = robots[i]+1;
          if (l) newrobotpos=max(newrobotpos, positions[l-1]+1);
          newrobots.push_back(newrobotpos);
        }
        while (newrobots.size() && newrobots.back() > n) {
          discard++;
          newrobots.pop_back();
        }
        robots = newrobots;
      }
      ans += robots.size() + discard;
    }
    cout << ans << '\n';
  }
}