#include <iostream>

using namespace std;

int main () {
  int n, m, mn, mx;
  cin >> n >> m >> mn >> mx;

  int cur_min = 105, cur_max = -1, vis_min = 1, vis_max = 1;
  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;

    cur_min = min(cur_min, temp);
    cur_max = max(cur_max, temp);
   
    if (temp == mn) {
      vis_min = 0;
    }

    if (temp == mx) {
      vis_max = 0;
    }
  }

  if (cur_min < mn) {
    cout << "Incorrect" << endl;
  } else if (cur_max > mx) {
    cout << "Incorrect" << endl;
  } else if (vis_min + vis_max > n - m) {
    cout << "Incorrect" << endl;
  } else {
    cout << "Correct" << endl;
  }
}