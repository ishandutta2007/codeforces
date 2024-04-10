#include <iostream>
#include <vector>

const int MAX_LEN = 100005;
const int SQRT = 316;

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int length, queryc;
  cin >> length >> queryc;
  
  vector<int> power (MAX_LEN, 0);
  for (int i = 0; i < length; i++) {
    cin >> power.at(i);
  }

  vector<int> uplink (MAX_LEN, -1), updist (MAX_LEN, 0);
  for (int i = 0; i < length; i++) {
    int cur = i;
    for (int j = 0; true; j++) {
      if (cur / SQRT != i / SQRT) {
        uplink.at(i) = cur;
        updist.at(i) = j;
        break;
      }
      
      if (cur + power.at(cur) >= length) {
        break;
      } else {
        cur += power.at(cur);
      }
    }
  }

  vector<int> changed (MAX_LEN, 0);
  for (int i = 0; i < queryc; i++) {
    int type;
    cin >> type;

    if (type == 0) {
      int pos, val;
      cin >> pos >> val;
      pos--;

      power.at(pos) = val;
      int cur = pos;
      for (int j = 0; true; j++) {
        if (cur / SQRT != pos / SQRT) {
          uplink.at(pos) = cur;
          updist.at(pos) = j;
          break;
        }
      
        if (cur + power.at(cur) >= length) {
          uplink.at(pos) = -1;
          break;
        } else {
          cur += power.at(cur);
        }
      }

      changed.at(pos) = true;
      for (int j = pos - 1; j / SQRT == pos / SQRT && j >= 0; j--) {
        if (j + power.at(j) < length && changed.at(j + power.at(j))) {
          changed.at(j) = true;
          uplink.at(j) = uplink.at(pos);
          updist.at(j) = updist.at(j + power.at(j)) + 1;
        }
      }

      for (int j = pos; j / SQRT == pos / SQRT && j >= 0; j--) {
        changed.at(j) = false;
      }
    } else {
      int pos;
      cin >> pos;
      pos--;

      int ans = 0;
      while (uplink.at(pos) != -1) {
        ans += updist.at(pos);
        pos = uplink.at(pos);
      }

      while (pos + power.at(pos) < length) {
        ans++;
        pos += power.at(pos);
      }

      cout << pos + 1 << " " << ans + 1 << '\n';
    }
  }
}