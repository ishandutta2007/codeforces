#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  int l = 0;
  int r = n-1;
  while (a[l] == a[n-1]) l++;
  while (a[r] == a[0]) r--;
  cout << max(n-1-l, r) << '\n';
}