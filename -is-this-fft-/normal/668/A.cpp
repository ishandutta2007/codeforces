#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
  int type;
  int r, c, x;
};

const int MAX_N = 105;

int grid [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m, qc;
  cin >> n >> m >> qc;

  vector<Query> qs;
  for (int i = 0; i < qc; i++) {
    Query q;
    cin >> q.type;

    if (q.type == 1) {
      cin >> q.r;
    } else if (q.type == 2) {
      cin >> q.c;
    } else {
      cin >> q.r >> q.c >> q.x;
    }
    
    q.r--;
    q.c--;

    qs.push_back(q);
  }

  reverse(qs.begin(), qs.end());

  for (auto q : qs) {
    if (q.type == 1) {
      int last = grid[q.r][m - 1];
      for (int i = m - 1; i > 0; i--) {
        grid[q.r][i] = grid[q.r][i - 1];
      }
      grid[q.r][0] = last;
    } else if (q.type == 2) {
      int last = grid[n - 1][q.c];
      for (int i = n - 1; i > 0; i--) {
        grid[i][q.c] = grid[i - 1][q.c];
      }
      grid[0][q.c] = last;
    } else {
      grid[q.r][q.c] = q.x;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j] << " ";
    }
    cout << '\n';
  }
}