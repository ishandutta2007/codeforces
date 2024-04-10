#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

int n;
ull ans[69];
vector <int> yo;

int main() {
  for (int mask = 0; mask < 1 << 13; ++mask) {
    if (__builtin_popcount(mask) == 6) {
      yo.emplace_back(mask);
    }
  }
  cin >> n;
  for (int i = 0; i < 13; ++i) {
    vector <int> cur;
    for (int j = 0; j < n; ++j) if (yo[j] & 1 << i) {
      cur.emplace_back(j + 1);
    }
    if (cur.empty()) continue;
    cout << "? " << cur.size();
    for (int x : cur) cout << " " << x; 
    cout << endl; cin >> ans[i];
  }
  cout << "!";
  for (int i = 0; i < n; ++i) {
    ull cur = 0;
    for (int j = 0; j < n; ++j) if (j ^ i) {
      for (int k = 0; k < 13; ++k) {
        if (yo[j] & 1 << k and ~yo[i] & 1 << k) {
          cur |= ans[k];
          break;
        }
      }
    }
    cout << " " << cur; 
  }
  cout << endl;
  return 0;
}