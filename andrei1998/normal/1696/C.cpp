#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long>> convert(vector<int> a, int m) {
  vector<pair<int, long long>> ans;
  for (int i = 0; i < a.size(); ++i) {
    int cnt = 1;
    while (a[i] % m == 0) {
      a[i] /= m;
      cnt *= m;
    }
    if (!ans.empty() && ans.back().first == a[i]) {
      ans.back().second += cnt;
    } else {
      ans.push_back(make_pair(a[i], cnt));
    }
  }
  return ans;
}

int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
      cin >> b[i];
    }
    if (convert(a, m) == convert(b, m)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}