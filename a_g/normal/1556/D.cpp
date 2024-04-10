#include <bits/stdc++.h>
using namespace std;

int recover(int seed, int val_and, int val_or) {
  return val_and + (val_or & (-1-seed));
}

int main () {
  int n, k;
  cin >> n >> k;
  vector<int> vals(n, 0);

  int and12, and13, and23, or12, or13, or23;
  cout << "and " << 1 << " " << 2 << endl;
  cin >> and12;
  cout << "and " << 1 << " " << 3 << endl;
  cin >> and13;
  cout << "and " << 2 << " " << 3 << endl;
  cin >> and23;
  cout << "or " << 1 << " " << 2 << endl;
  cin >> or12;
  cout << "or " << 1 << " " << 3 << endl;
  cin >> or13;
  cout << "or " << 2 << " " << 3 << endl;
  cin >> or23;
  vals[0] = (or12 & or13) - (and23 & (-1-and12 & and23));
  vals[1] = recover(vals[0], and12, or12);
  vals[2] = recover(vals[0], and13, or13);

  for (int j = 4; j <= n; j++) {
    int val_and, val_or;
    cout << "and " << 1 << " " << j << endl;
    cin >> val_and;
    cout << "or " << 1 << " " << j << endl;
    cin >> val_or;
    vals[j-1] = recover(vals[0], val_and, val_or);
  }
  sort(vals.begin(), vals.end());
  cout << "finish " << vals[k-1] << endl;
}