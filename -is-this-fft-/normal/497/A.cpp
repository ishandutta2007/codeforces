#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 105;

string grid [MAX_N];
int pref [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  int ans = 0;
  for (int j = 0; j < m; j++) {
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (grid[i][j] > grid[i + 1][j] && pref[i] == pref[i + 1]) {
        ok = false;
      }
    }

    if (ok) {
      char lastv = 0;
      int lastopr = -1, lastnpr = -1;
      for (int i = 0; i < n; i++) {
        int tmp = pref[i];
        if (lastopr != pref[i]) {
          pref[i] = lastnpr + 1;
        } else if (grid[i][j] > lastv) {
          pref[i] = lastnpr + 1;
        } else {
          pref[i] = lastnpr;
        }
        lastv = grid[i][j];
        lastnpr = pref[i];
        lastopr = tmp;
      }
    } else {
      ans++;
    }
  }

  cout << ans << endl;
}