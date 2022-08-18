#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 255;

int ans [MAX_N][MAX_N];
vector<int> frees;

int r, c;

void add (int val, bool rowm, bool colm) {
  if (rowm) r++;
  if (colm) c++;
  ans[r][c] = val;
  
  if (rowm) {
    for (int i = c - 1; i >= 0; i--) {
      ans[r][i] = frees.back();
      frees.pop_back();
    }
  }

  if (colm) {
    for (int i = r - 1; i >= 0; i--) {
      ans[i][c] = frees.back();
      frees.pop_back();
    }
  }
}

int grid [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  
  set<int> rowms;
  for (int i = 0; i < n; i++) {
    int mx = -1;
    for (int j = 0; j < m; j++) {
      mx = max(mx, grid[i][j]);
    }
    rowms.insert(mx);
  }
  rowms.insert(0);
  
  set<int> colms;
  for (int j = 0; j < m; j++) {
    int mx = -1;
    for (int i = 0; i < n; i++) {
      mx = max(mx, grid[i][j]);
    }
    colms.insert(mx);
  }
  colms.insert(0);

  for (int i = 1; i <= n * m; i++) {
    if (!rowms.count(i) && !colms.count(i)) {
      frees.push_back(i);
    }
  }

  r = -1; c = -1;
  while ((int) rowms.size() > 1 || (int) colms.size() > 1) {
    int mx = max(*rowms.rbegin(), *colms.rbegin());
    add(mx, rowms.count(mx), colms.count(mx));
    rowms.erase(mx);
    colms.erase(mx);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
}