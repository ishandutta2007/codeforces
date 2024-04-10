#include <iostream>

using namespace std;

const int MAX_H = 105;

int cur_row [MAX_H];
int cur_col [MAX_H];
int target_row [MAX_H];
int target_col [MAX_H];
int ans [MAX_H][MAX_H];

void set_val (int r, int c, int val) {
  ans[r][c] = val;
  cur_row[r] ^= val;
  cur_col[c] ^= val;
}

int main () {
  int height, width;
  cin >> height >> width;

  int rowsum = 0;
  for (int i = 0; i < height; i++) {
    cin >> target_row[i];
    rowsum ^= target_row[i];
  }

  int colsum = 0;
  for (int i = 0; i < width; i++) {
    cin >> target_col[i];
    colsum ^= target_col[i];
  }

  if (rowsum != colsum) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < max(height, width); i++) {
    if (width <= height) {
      int val = cur_row[i] ^ target_row[i];
      set_val(i % height, i % width, val);

      if (i != max(height, width) - 1) {
        int corr_val = cur_col[i % width] ^ target_col[i % width];
        set_val((i + 1) % height, i % width, corr_val);
      }
    } else {
      int val = cur_col[i] ^ target_col[i];
      set_val(i % height, i % width, val);

      if (i != max(height, width) - 1) {
        int corr_val = cur_row[i % height] ^ target_row[i % height];
        set_val(i % height, (i + 1) % width, corr_val);
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
}