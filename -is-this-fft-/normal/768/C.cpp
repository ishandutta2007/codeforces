#include <iostream>
#include <queue>

const int MAX_STR = 1024;

using namespace std;

int cnt [MAX_STR], upd [MAX_STR];

int main () {
  ios::sync_with_stdio(false);

  int rangerc, opc, fav;
  cin >> rangerc >> opc >> fav;

  for (int i = 0; i < rangerc; i++) {
    int ranger;
    cin >> ranger;

    cnt[ranger]++;
  }

  for (int i = 0; i < opc; i++) {
    int cur_flip = 0;
    for (int j = 0; j < MAX_STR; j++) {
      if (cur_flip % 2 == 1) {
        upd[j] -= cnt[j] / 2;
        upd[j ^ fav] += cnt[j] / 2;
      } else {
        upd[j] -= (cnt[j] + 1) / 2;
        upd[j ^ fav] += (cnt[j] + 1) / 2;
      }

      cur_flip += cnt[j];
    }

    for (int j = 0; j < MAX_STR; j++) {
      cnt[j] += upd[j];
      upd[j] = 0;
    }
  }

  int low;
  for (int i = 0; i < MAX_STR; i++) {
    if (cnt[i] != 0) {
      low = i;
      break;
    }
  }

  int hi;
  for (int i = MAX_STR - 1; i >= 0; i--) {
    if (cnt[i] != 0) {
      hi = i;
      break;
    }
  }

  cout << hi << " " << low << endl;
}