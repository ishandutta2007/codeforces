#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) cin >> grid[i];
  auto findword = [&] (string s) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int dx = 0; dx <= 1; dx++) {
          for (int dy = 0; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            bool found = 1;
            for (int k = 0; k < s.size(); k++) {
              int u = i+k*dx;
              int v = j+k*dy;
              if (u < 0 || u >= n || v < 0 || v >= n) {
                found = 0;
                break;
              }
              if (grid[u][v] != s[k]) {
                found = 0;
                break;
              }
            }
            if (found) ans++;
          }
        }
      }
    }
    return ans;
  };
  cout << (findword("theseus") ? "YES" : "NO") << '\n';
}