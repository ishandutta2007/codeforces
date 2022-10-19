#include <bits/stdc++.h>
using namespace std;

vector<pair<int, long long>> calc(vector<int>& a, int m) {
  vector<pair<int, long long>> ans;
  for (int& x: a) {
    int c = 1;
    int v = x;
    while (v%m == 0) {
      v /= m;
      c *= m;
    }
    if (ans.size() && ans.back().first == v) {
      ans.back().second += c;
    }
    else {
      ans.emplace_back(v, c);
    }
  }
  return ans;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    int k;
    cin >> k;
    vector<int> b(k);
    for (int& x: b) cin >> x;
    cout << (calc(a, m) == calc(b, m) ? "Yes" : "No") << '\n';
  }
}