#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int b, k;
  cin >> b >> k;
  vector<int> a(k);
  for (int& x: a) cin >> x;
  int s = accumulate(a.begin(), a.end(), 0);
  if (b%2 == 0) s = a[k-1];
  cout << (s&1 ? "odd" : "even") << '\n';
}