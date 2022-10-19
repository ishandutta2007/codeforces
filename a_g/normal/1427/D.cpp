#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int& x: c) cin >> x;
  bool rev = 1;
  vector<vector<int>> ops;
  auto work = [&] (vector<int> op) {
    if (op.back() == 0) op.pop_back();
    assert(accumulate(op.begin(), op.end(), 0) == n);
    rev ^= 1;
    int start = 0;
    for (int v: op) {
      reverse(c.begin()+start, c.begin()+start+v);
      start += v;
    }
    if (op.size() == 1) return;
    if (rev) reverse(op.begin(), op.end());
    ops.push_back(op);
  };

  auto debug = [&] () {
    for (int k: c) {
      cout << k << ' ';
    }
    cout << '\n';
  };

  for (int i = 1; i < n; i++) {
    int a = find(c.begin(), c.end(), i) - c.begin();
    vector<int> op(i-1, 1);
    op.push_back(a-i+2);
    op.push_back(n-1-a);
    work(op);
    //debug();
  }
  if (n % 2 == 0) {
    work(vector<int>(n, 1));
  }

  cout << ops.size() << '\n';
  for (vector<int>& op: ops) {
    cout << op.size() << ' ';
    for (int k: op) {
      cout << k << ' ';
    }
    cout << '\n';
  }
}