#include <bits/stdc++.h>
using namespace std;

// #define int long long

typedef long long ll;
typedef long double ldb;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] -= x;
  }
  int cnt = 0;
  int l = INT_MAX;
  int r = INT_MIN;
  set<int> ss;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      ss.insert(a[i]);
      l = min(l, i);
      r = max(r, i);
      cnt++;
    }
  }
  if (ss.empty() || (ss.size() == 1 && r - l + 1 == cnt && *ss.begin() < 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  }
  return 0;
}