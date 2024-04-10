#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int n, k, a, val;
  cin >> n >> k;
  int maxval = 0;
  int minval = n+1;
  map<int, int> freqs;
  for (int i = 1; i <= k+1; i++) {
    cout << "? ";
    for (int j = 1; j <= k+1; j++) {
      if (j != i) cout << j << " ";
    }
    cout << endl;
    cin >> a >> val;
    maxval = max(val, maxval);
    minval = min(val, minval);
    freqs[val]++;
  }
  cout << "! " << freqs[maxval] << endl;
}