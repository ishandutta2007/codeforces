#include <iostream>
#include <string>

using namespace std;

/*
bool at (int x, int i) {
  return !!(x & 1 << i);
}

bool all_same (bool x, bool y, bool z) {
  return x == y && y == z;
}

bool is_good (int x) {
  if (all_same(at(x, 0), at(x, 1), at(x, 2))) return 0;
  if (all_same(at(x, 1), at(x, 2), at(x, 3))) return 0;
  if (all_same(at(x, 2), at(x, 3), at(x, 4))) return 0;
  if (all_same(at(x, 3), at(x, 4), at(x, 5))) return 0;
  if (all_same(at(x, 4), at(x, 5), at(x, 6))) return 0;
  if (all_same(at(x, 5), at(x, 6), at(x, 7))) return 0;
  if (all_same(at(x, 6), at(x, 7), at(x, 8))) return 0;
  
  if (all_same(at(x, 0), at(x, 2), at(x, 4))) return 0;
  if (all_same(at(x, 1), at(x, 3), at(x, 5))) return 0;
  if (all_same(at(x, 2), at(x, 4), at(x, 6))) return 0;
  if (all_same(at(x, 3), at(x, 5), at(x, 7))) return 0;
  if (all_same(at(x, 4), at(x, 6), at(x, 8))) return 0;
  
  if (all_same(at(x, 0), at(x, 3), at(x, 6))) return 0;
  if (all_same(at(x, 1), at(x, 4), at(x, 7))) return 0;
  if (all_same(at(x, 2), at(x, 5), at(x, 8))) return 0;

  if (all_same(at(x, 0), at(x, 4), at(x, 8))) return 0;
  return 1;
}
*/

int main () {
  string s;
  cin >> s;

  long long ans = 0;
  int left_end = -1;
  for (int i = 0; i < (int) s.size(); i++) {
    for (int j = 1; j <= 100 && i - 2 * j >= 0; j++) {
      if (s[i] == s[i - j] && s[i - j] == s[i - 2 * j]) {
        left_end = max(left_end, i - 2 * j);
        break;
      }
    }
    ans += left_end + 1;
  }

  cout << ans << endl;
}