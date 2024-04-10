#include <bits/stdc++.h>
using namespace std;

int query(string s, int i, int j) {
  cout << s << ' ' << i+1 << ' ' << j+1 << endl;
  int x;
  return cin >> x, x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> indices(n);
  indices[0].push_back(0);
  for (int i = 1; i < n; i++) {
    a[i] = query("XOR", 0, i);
    indices[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if ((int)indices[i].size() > 1) {
      int o = query("OR", indices[i][0], indices[i][1]);
      cout << "!";
      for (int& x: a) cout << ' ' << (x^(o^i));
      cout << endl;
      return 0;
    }
  }

  for (int y: {1, n-2}) {
    int o = query("OR", 0, indices[y][0]);
    for (int& x: a) x ^= (o^y);
  }
  cout << "!";
  for (int& x: a) cout << ' ' << x;
  cout << endl;
  return 0;
}