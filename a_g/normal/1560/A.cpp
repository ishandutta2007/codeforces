#include <bits/stdc++.h>
using namespace std;

bool valid(int val) {
  if (val % 3 == 0) return 0;
  if (val % 10 == 3) return 0;
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> vals;
  int val = 1;
  while (vals.size() < 1005) {
    if (valid(val)) vals.push_back(val);
    val++;
  }
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    cout << vals[k-1] << endl;
  }
}