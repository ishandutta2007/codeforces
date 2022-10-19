#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> a;
  for (char c: s) a.push_back(c-'0');
  int n = a.size();
  for (int i = n-2; i >= 0; i--) {
    if (a[i] + a[i+1] >= 10) {
      for (int j = 0; j < i; j++) cout << a[j];
      cout << a[i]+a[i+1];
      for (int j = i+2; j < n; j++) cout << a[j];
      cout << '\n';
      return;
    }
  }

  for (int i = 0; i < n-1; i++) {
    if (a[i+1] >= 0) {
      for (int j = 0; j < i; j++) cout << a[j];
      cout << a[i]+a[i+1];
      for (int j = i+2; j < n; j++) cout << a[j];
      cout << '\n';
      return;
    }
  }

  for (int i = 0; i < n-1; i++) cout << a[i];
  cout << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}