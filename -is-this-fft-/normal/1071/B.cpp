#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

char grid [MAX_N][MAX_N];
int cnta [MAX_N][MAX_N];

int main () {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnta[i][j] = 0;
      if (i != 0) cnta[i][j] = max(cnta[i][j], cnta[i - 1][j]);
      if (j != 0) cnta[i][j] = max(cnta[i][j], cnta[i][j - 1]);
      if (grid[i][j] == 'a') cnta[i][j]++;
    }
  }

  vector<pair<int, int>> fline;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cnta[i][j] + k >= i + j + 1) {
        // we can fill the prefix!
        if (fline.empty()) fline.push_back({i, j});
        else {
          if (fline[0].first + fline[0].second == i + j) {
            fline.push_back({i, j});
          } else if (fline[0].first + fline[0].second < i + j) {
            fline.clear();
            fline.push_back({i, j});
          }
        }
      }
    }
  }

  if (fline.empty()) {
    fline.push_back({0, 0});
    cout << grid[0][0];
  } else {
    for (int i = 0; i < fline[0].first + fline[0].second + 1; i++) {
      cout << 'a';
    }
  }
  
  while (fline[0] != make_pair(n - 1, n - 1)) {    
    char bestn = 'z' + 1;
    for (auto pr : fline) {
      if (pr.first != n - 1) {
        bestn = min(bestn, grid[pr.first + 1][pr.second]);
      }

      if (pr.second != n - 1) {
        bestn = min(bestn, grid[pr.first][pr.second + 1]);
      }
    }

    cout << bestn;
    
    vector<pair<int, int>> nline;
    for (auto pr : fline) {
      if (pr.second != n - 1 && grid[pr.first][pr.second + 1] == bestn) {
        if (nline.empty() || nline.back() != make_pair(pr.first, pr.second + 1)) {
          nline.push_back({pr.first, pr.second + 1});
        }
      }

      if (pr.first != n - 1 && grid[pr.first + 1][pr.second] == bestn) {
        nline.push_back({pr.first + 1, pr.second});
      }
    }
    fline = nline;
  }

  cout << endl;
}