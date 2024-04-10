#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

vector<vector<int>> arr;

const int dx [4] = {1, 0, -1, 0};
const int dy [4] = {0, 1, 0, -1};

const int nx [5] = {1, 0, -1, 0, 0};
const int ny [5] = {0, 1, 0, -1, 0};

bool is_loc_min (int x, int y) {
  for (int k = 0; k < 4; k++) {
    if (arr[x][y] >= arr[x + dx[k]][y + dy[k]]) {
      return false;
    }
  }
  return true;
}

vector<vector<int>> loc_min;
int lmc;

void recalc (int x, int y) {
  lmc -= loc_min[x][y];
  loc_min[x][y] = is_loc_min(x, y);
  lmc += loc_min[x][y];
}

void recalc_nb (int x, int y) {
  for (int k = 0; k < 5; k++) {
    recalc(x + nx[k], y + ny[k]);
  }
}

bool is_swp (int x1, int y1, int x2, int y2) {
  swap(arr[x1][y1], arr[x2][y2]);
  recalc_nb(x1, y1);
  recalc_nb(x2, y2);
  bool ok = lmc == 1;
  swap(arr[x1][y1], arr[x2][y2]);
  recalc_nb(x1, y1);
  recalc_nb(x2, y2);
  return ok;  
}

bool has_lm_nb (int x, int y) {
  for (int k = 0; k < 5; k++) {
    if (loc_min[x + nx[k]][y + ny[k]] && arr[x + nx[k]][y + ny[k]] != 1) {
      return true;
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  arr = vector<vector<int>> (n + 4, vector<int> (m + 4, INF));
  for (int i = 2; i < n + 2; i++) {
    for (int j = 2; j < m + 2; j++) {
      cin >> arr[i][j];
    }
  }

  loc_min = vector<vector<int>> (n + 4, vector<int> (m + 4, 0));
  for (int i = 1; i < n + 3; i++) {
    for (int j = 1; j < m + 3; j++) {
      loc_min[i][j] = is_loc_min(i, j);
      lmc += loc_min[i][j];
    }
  }

  if (lmc == 1) {
    cout << 0 << '\n';
    return 0;
  }

  if (lmc > 6) {
    cout << 2 << '\n';
    return 0;
  }

  int ans = 0;
  for (int i = 2; i < n + 2; i++) {
    for (int j = 2; j < m + 2; j++) {
      if (!has_lm_nb(i, j)) {
        continue;
      }
      
      for (int ii = 2; ii < n + 2; ii++) {
        for (int jj = 2; jj < m + 2; jj++) {
          if (has_lm_nb(ii, jj) && make_pair(ii, jj) <= make_pair(i, j)) {
            continue;
          }

          if (is_swp(i, j, ii, jj)) {
            ans++;
          }
        }
      }
    }
  }

  if (ans == 0) {
    cout << 2 << '\n';
  } else {
    cout << 1 << " " << ans << '\n';
  }
}