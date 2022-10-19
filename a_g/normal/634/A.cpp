#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& x: a) cin >> x;
  for (int& x: b) cin >> x;
  a.erase(find(a.begin(), a.end(), 0));
  b.erase(find(b.begin(), b.end(), 0));
  rotate(a.begin(), find(a.begin(), a.end(), 1), a.end());
  rotate(b.begin(), find(b.begin(), b.end(), 1), b.end());
  cout << (a == b ? "YES" : "NO") << '\n';
}