#include <iostream>

using namespace std;

int main () {
  int studc;
  cin >> studc;

  int opsum = 0, mx = 0;
  for (int i = 0; i < studc; i++) {
    int ai;
    cin >> ai;

    mx = max(mx, ai);
    opsum += ai;
  }

  for (int j = mx; true; j++) {
    if (j * studc - opsum > opsum) {
      cout << j << endl;
      return 0;
    }
  }
}