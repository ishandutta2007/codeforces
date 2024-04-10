#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<bool> present(n+1);
  vector<int> extras;
  vector<int> missing;
  for (int i = 0; i < n; i++) {
    if (a[i] <= n && !present[a[i]]) {
      present[a[i]] = 1;
    }
    else {
      extras.push_back(a[i]);
    }
  }
  sort(extras.begin(), extras.end());
  for (int i = 1; i <= n; i++) {
    if (!present[i]) missing.push_back(i);
  }
  for (int i = 0; i < extras.size(); i++) {
    if (extras[i] <= 2*missing[i]) return -1;
  }
  return extras.size();
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << '\n';
  }
}