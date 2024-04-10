#include <iostream>
#include <algorithm>
#include <string>

const int MAX_STRING = 55;

using namespace std;

int fnum [MAX_STRING], flet [MAX_STRING], fspe [MAX_STRING];

int main () {
  int stringc, length;
  cin >> stringc >> length;

  for (int i = 0; i < stringc; i++) {
    string cur;
    cin >> cur;

    fnum[i] = 1000;
    flet[i] = 1000;
    fspe[i] = 1000;

    for (int j = length - 1; j >= 0; j--) {
      if (cur[j] <= '9' && cur[j] >= '0') {
        fnum[i] = min(fnum[i], min(j, length - j));
      } else if (cur[j] <= 'z' && cur[j] >= 'a') {
        flet[i] = min(flet[i], min(j, length - j));
      } else {
        fspe[i] = min(fspe[i], min(j, length - j));
      }
    }
  }

  int ans = 5000;
  for (int i = 0; i < stringc; i++) {
    for (int j = 0; j < stringc; j++) {
      for (int k = 0; k < stringc; k++) {
        if (i != j && j != k && i != k) {
          ans = min(ans, fnum[i] + flet[j] + fspe[k]);
        }
      }
    }
  }

  cout << ans << endl;
}