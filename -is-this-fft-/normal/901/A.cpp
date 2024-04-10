#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int h;
  cin >> h;
  h++;
  for (int i = 0; i < h; i++) {
    cin >> arr[i];
  }

  int spike = -1;
  for (int i = 0; i < h - 1; i++) {
    if (arr[i] != 1 && arr[i + 1] != 1) {
      spike = i;
    }
  }

  if (spike < 0) {
    cout << "perfect" << endl;
    return 0;
  }

  cout << "ambiguous" << endl;

  int last = 0, cur = 1;
  for (int i = 0; i < h; i++) {
    int nlast = cur;
    for (int j = 0; j < arr[i]; j++) {
      cout << last << " ";
      cur++;
    }
    last = nlast;
  }
  cout << endl;

  last = 0, cur = 1;
  for (int i = 0; i < h; i++) {
    if (i == spike + 1) {
      int nlast = cur;
      for (int j = 0; j < arr[i] - 1; j++) {
        cout << last << " ";
        cur++;
      }
      cout << last + 1 << " ";
      cur++;
      last = nlast;
    } else {
      int nlast = cur;
      for (int j = 0; j < arr[i]; j++) {
        cout << last << " ";
        cur++;
      }
      last = nlast;
    }
  }
  cout << endl;
}