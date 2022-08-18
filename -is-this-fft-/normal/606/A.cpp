#include <iostream>

using namespace std;

int have [3], need [3];

int main () {
  cin >> have[0] >> have[1] >> have[2]
      >> need[0] >> need[1] >> need[2];

  for (int i = 0; i < 3; i++) {
    if (need[i] <= have[i]) {
      have[i] -= need[i];
      need[i] = 0;
    } else {
      need[i] -= have[i];
      have[i] = 0;
    }

    if (have[i] % 2 == 1) {
      have[i]--;
    }
  }

  int havesum = have[0] + have[1] + have[2];
  int needsum = need[0] + need[1] + need[2];

  cout << (havesum >= needsum * 2 ? "Yes" : "No") << endl;
}