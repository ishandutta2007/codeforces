#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
  int n;
  string str;
  cin >> n >> str;

  vector<int> blocks;
  int tot_gld = 0;
  for (int i = 0; i < n; i++) {
    char c = str[i];
    if (i == 0 || c != str[i - 1]) {
      blocks.push_back(0);
    }
    blocks.back()++;

    if (c == 'G') tot_gld++;
  }

  if (tot_gld == n) {
    cout << n << '\n';
    return 0;
  }

  if (tot_gld == 0) {
    cout << 0 << '\n';
    return 0;
  }

  int ans = 0;
  int start = (str[0] == 'G' ? 0 : 1);
  for (int i = start; i < (int) blocks.size(); i += 2) {
    ans = max(ans, blocks[i]);
    if (blocks[i] != tot_gld) {
      ans = max(ans, blocks[i] + 1);
    }

    if (i + 2 < (int) blocks.size()) {
      if (blocks[i + 1] == 1) {
        if (blocks[i] + blocks[i + 2] != tot_gld) {
          ans = max(ans, blocks[i] + blocks[i + 2] + 1);
        } else {
          ans = max(ans, blocks[i] + blocks[i + 2]);
        }
      }
    }
  }

  cout << ans << '\n';
}