#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  cout << (count(a.begin(), a.end(), *min_element(a.begin(), a.end())) <= n/2 ? "Alice" : "Bob") << '\n';
}