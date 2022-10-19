#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<int> d(n+1);
  for (int i = 0; i < n; i++) d[i+1] = d[i]+s[i]-t[i];
  cout << (d[n] == 0 ? *max_element(d.begin(), d.end())-*min_element(d.begin(), d.end()): -1) << '\n';
}