#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 305;

char grid [MAX_N][MAX_N];

void solve () {
  int n;
  cin >> n;

  vector<int> xc (3, 0);
  vector<int> oc (3, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 'X') {
        xc[(i + j) % 3]++;
      } else if (grid[i][j] == 'O') {
        oc[(i + j) % 3]++;
      }
    }
  }

  vector<pair<int, int>> xcp;
  for (int i = 0; i < 3; i++) {
    xcp.push_back(make_pair(xc[i], i));
  }
  sort(xcp.begin(), xcp.end());

  vector<pair<int, int>> ocp;
  for (int i = 0; i < 3; i++) {
    ocp.push_back(make_pair(oc[i], i));
  }
  sort(ocp.begin(), ocp.end());

  vector<char> targets (3, 0);
  if (xcp[0].second != ocp[0].second) {
    targets[xcp[0].second] = 'O';
    targets[ocp[0].second] = 'X';
  } else if (xcp[0].first + ocp[1].first < xcp[1].first + ocp[0].first) {
    targets[xcp[0].second] = 'O';
    targets[ocp[1].second] = 'X';
  } else {
    targets[xcp[1].second] = 'O';
    targets[ocp[0].second] = 'X';
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '.' || targets[(i + j) % 3] == 0) {
        cout << grid[i][j];
      } else {
        cout << targets[(i + j) % 3];
      }
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}