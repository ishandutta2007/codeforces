#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> query(vector<int>& a) {
  cout << a.size() << '\n';
  for (int x: a) {
    cout << x+1 << ' ';
  }
  cout << endl;
  vector<int> ans(n);
  for (int& x: ans) cin >> x;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> ans(n, 1e9);
  for (int b = 0; b < 10; b++) {
    for (int z = 0; z < 2; z++) {
      vector<int> a;
      for (int i = 0; i < n; i++) {
        if (((i>>b)&1) == z) a.push_back(i);
      }
      if (!a.size()) continue;
      vector<int> response = query(a);
      for (int i = 0; i < n; i++) {
        if (((i>>b)&1) != z) ans[i] = min(ans[i], response[i]);
      }
    }
  }
  cout << "-1\n";
  for (int x: ans) {
    cout << x << ' ';
  }
  cout << endl;
}