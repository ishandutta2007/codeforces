#include <iostream>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int main () {
  int n, d, h;
  cin >> n >> d >> h;

  if (d == 1) {
    if (h != 1) failure();
    if (n != 2) failure();
    cout << 1 << " " << 2 << endl;
    return 0;
  }

  if (2 * h < d) failure();

  int last = 0;
  for (int i = 1; i <= h; i++) {
    cout << i << " " << i + 1 << '\n';
    last = i + 1;
  }

  // cerr << " === " << endl;
  
  if (h < d) {
    cout << 1 << " " << last + 1 << '\n';
    last++;

    for (int i = 0; i < d - h - 1; i++) {
      cout << last << " " << last + 1 << '\n';
      last++;
    }
  }

  // cerr << " == " << endl;

  while (last < n) {
    cout << h << " " << last + 1 << '\n';
    last++;
  }
}