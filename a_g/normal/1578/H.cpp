#include <bits/stdc++.h>
using namespace std;


bool compare(const pair<string, int>& x, const pair<string, int>& y) {
  string xs = x.first;
  string ys = y.first;
  int m = xs.length();
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (xs[i] < ys[i]) return true;
      if (xs[i] > ys[i]) return false;
    }
    else {
      if (ys[i] < xs[i]) return true;
      if (ys[i] > xs[i]) return false;
    }
  }
  return false;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = {s, i+1};
  }
  sort(a.begin(), a.end(), compare);
  for (pair<string, int> p: a) {
    cout << p.second << " ";
  }
  cout << endl;
}