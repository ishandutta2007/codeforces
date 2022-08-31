#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;

  vector<int> cyc;
  for (int i = 0; i < k; i++) {
    cyc.push_back(i);
    cyc.push_back(i);
    for (int j = i + 2; j < k; j++) {
      if ((j + 1) % k != i) {
        cyc.push_back(j);
        cyc.push_back(i);
      }
    }
  }
  cyc.push_back(0);
  for (int i = k - 1; i > 0; i--) {
    cyc.push_back(i);
  }

  if (k == 2) {
    cyc = {0, 0, 1, 1};
  }

  for (int i = 0; i < n; i++) {
    cout << (char) ('a' + cyc[i % cyc.size()]);
  }
  cout << '\n';
}